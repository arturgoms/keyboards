#pragma once

#include "layers.h"

// Custom keycodes

enum {
    SS_SECRET_1 = SAFE_RANGE,
    SS_SECRET_2, SS_SECRET_3,

    SS_BTIC, SS_DQUO, SS_SQUO,
    SS_CIRC, SS_TILD, SS_DEG,

    TG_MAC, TG_WIN, TG_LIN,

    SP_CAP, SP_MOD, SP_NG, SP_ALT,

    SS_MODP, SS_MODM,

    SS_GV_A, SS_CR_A, SS_TL_A, SS_SQ_A,
    SS_SQ_U, SS_CR_O, SS_SQ_O, SS_SQ_I,
    SS_CR_E, SS_TL_O, SS_SQ_C, SS_SQ_E,

    SS_SELW, SS_SWIN, SS_CAPS,

    SS_RS,  SS_EY,  SS_PH,  SS_CK,  SS_AU,  
    SS_CH,  SS_SH,  SS_HE,  SS_NH,  SS_GH,
    SS_WH,  SS_IO,  SS_YE,  SS_TH,  SS_ING, SS_LH,

    SS_DAND, SS_DPIP, 
    SS_EQU, SS_NEQ, 
    SS_ARR, SS_DDS, 

    SS_AO, SS_CAO, SS_OES, SS_COES
};

// Mod-taps

#define LSFTT_S LSFT_T(KC_S)
#define RSFTT_L RSFT_T(KC_L)
#define RSFTT_O RSFT_T(KC_O)
#define SF_F6 LSFT_T(KC_F6)
#define SF_P6 RSFT_T(KC_P6)

#define LCTLT_D LCTL_T(KC_D)
#define LCTLT_E LCTL_T(KC_E)
#define RCTLT_K RCTL_T(KC_K)
#define RCTLT_A RCTL_T(KC_A)
#define CT_F5 LCTL_T(KC_F5)
#define CT_P5 RCTL_T(KC_P5)

#define LALTT_F LALT_T(KC_F)
#define LALTT_D LALT_T(KC_D)
#define RALTT_J RALT_T(KC_J)
#define RALTT_N RALT_T(KC_N)
#define AL_F4 LALT_T(KC_F4)
#define AL_P4 RALT_T(KC_P4)
#define LA_UNDS LALT_T(KC_UNDS)

#define LGUIT_V LGUI_T(KC_V)
#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_M RGUI_T(KC_M)
#define GU_F1 LGUI_T(KC_F1)
#define GU_P1 RGUI_T(KC_P1)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MED_CAP LT(_MEDIA, SP_CAP)
#define MED_0   LT(_MEDIA, KC_0)
#define MED_P0  LT(_MEDIA, KC_P0)

#define NAV_NG  LT(_NAVIGATION, SP_NG)
#define MAI_MOD LT(_MAINTENANCE, SP_MOD)
#define MAI_ALT LT(_MAINTENANCE, SP_ALT)
#define MED_ALT LT(_MEDIA, SP_ALT)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)

#define NUM_SPC LT(_NUMPAD, KC_SPC)
#define NUM_BSP LT(_NUMPAD, KC_BSPC)

#define KCA_MAC LT(_MACROS, KC_A)
#define KCF_MAC LT(_MACROS, KC_F)
#define KCC_MAC LT(_MACROS, KC_C)
#define SCL_MAC LT(_MACROS, KC_SCLN)
#define UND_MAC LT(_MACROS, KC_UNDS)
#define DOT_MAC LT(_MACROS, KC_DOT)
#define PDO_MAC LT(_MACROS, KC_PDOT)

#define PER_LOW LT(_LOWER_CLONE, KC_PERC)
#define BTI_RAI LT(_RAISE, SS_BTIC)

// Layer transitions

#define TO_ROM TO(_ROMAK)
#define TG_NUM TG(_NUMPAD)
#define TG_NAV TG(_FIXED_NAV)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define SC_SELC LGUI(KC_A)
#define SC_SAVE LGUI(KC_S)
#define SC_UNDO LGUI(KC_Z)
#define SC_COPY LGUI(KC_C)
#define SC_PAST LGUI(KC_V)
#define SC_LOCK LGUI(LCTL(KC_Q))
#define SC_FULL LGUI(LCTL(KC_F))
#define SC_FIND LGUI(KC_F)

uint16_t extract_base_tapping_keycode(uint16_t keycode);