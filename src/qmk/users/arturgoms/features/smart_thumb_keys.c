#include QMK_KEYBOARD_H

#include "smart_thumb_keys.h"

extern os_t           os;
extern ngrams_timer_t ngrams_timer;

bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
    return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
}

process_record_result_t process_smart_thumb_keys(uint16_t keycode, keyrecord_t *record) {
    bool isWindowsOrLinux    = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotDefaultMod = (!isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_GUI)) ||
                               (isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_CTRL));
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;

    switch (keycode) {
        case NAV_NG:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_NGRAMS)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_NGRAMS, ONESHOT_START);
                        ngrams_timer.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case MED_SFT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_any_smart_case()) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (isAnyOneShotButShift || isOneShotLockedShift) {
                            clear_locked_and_oneshot_mods();
                        } else if (!isOneShotShift && get_mods() == 0) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            set_smart_case_for_mods(record);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case MAI_ALT:
        case MED_ALT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isOneShotLockedShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (!isOneShotAlt) {
                        if (isOneShotShift) {
                            clear_locked_and_oneshot_mods();
                        }
                        add_oneshot_mods(MOD_RALT);
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

        case MAI_MOD:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isOneShotLockedShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (!isOneShotDefaultMod) {
                        if (isOneShotShift) {
                            clear_locked_and_oneshot_mods();
                        }
                        if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                            add_oneshot_mods(MOD_LCTL);
                        } else {
                            add_oneshot_mods(MOD_LGUI);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;
    }

    return PROCESS_RECORD_CONTINUE;
}
