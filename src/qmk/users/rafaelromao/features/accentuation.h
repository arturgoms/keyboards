#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "smart_thumb_keys.h"

process_record_result_t process_accentuated_characters(uint16_t keycode, keyrecord_t *record);
