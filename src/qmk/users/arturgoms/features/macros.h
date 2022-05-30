#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "smart_thumb_keys.h"

typedef struct {
    uint16_t timer;
} ngrams_timer_t;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record);
void                    check_ngrams_timeout(void);
