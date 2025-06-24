#include QMK_KEYBOARD_H

// Layer names
enum layer_names {
    _MAC,
    _SYM,
    _NUM,
    _NAV,
    _FUN,
    _WIN,
};

// Homerow mod-tap for Mac layer
#define MT_LC_A MT(MOD_LCTL, KC_A)
#define MT_LA_R MT(MOD_LALT, KC_R)
#define MT_LG_S MT(MOD_LGUI, KC_S)
#define MT_LS_T MT(MOD_LSFT, KC_T)
// --
#define MT_RS_N MT(MOD_RSFT, KC_N)
#define MT_RG_E MT(MOD_RGUI, KC_E)
#define MT_RA_I MT(MOD_RALT, KC_I)
#define MT_RC_O MT(MOD_RCTL, KC_O)

// Homerow mod-tap for symbol layer
#define MT_LC_AS MT(MOD_LCTL, KC_AT) // at
#define MT_LA_RS MT(MOD_LALT, KC_MINUS)
#define MT_LG_SS MT(MOD_LGUI, KC_PLUS) // Plus
#define MT_LS_TS MT(MOD_LSFT, KC_EQUAL)
// --
#define MT_RS_NS MT(MOD_RSFT, KC_LPRN) // (
#define MT_RG_ES MT(MOD_RGUI, KC_LCBR) // {
#define MT_RA_IS MT(MOD_RALT, KC_RCBR) // }
#define MT_RC_OS MT(MOD_RCTL, KC_RPRN) // )

// Hyper key definition
#define MT_RG_DEL ALL_T(KC_DEL) // Hyper + Delete

// Layer-tap definitions
#define LT_WIN_ESC LT(_WIN, KC_ESC)
#define LT_NUM_BSPC LT(_NUM, KC_BSPC)
#define LT_FUN_TAB LT(_FUN, KC_TAB)
#define LT_NAV_RET LT(_NAV, KC_ENT)
#define LT_SYM_SPC LT(_SYM, KC_SPC)

// Macro definitions for Windows (_WIN) layer
#define S_G_A_C_N1 LCTL(LSFT(LALT(LGUI(KC_1))))
#define S_G_A_C_N2 LCTL(LSFT(LALT(LGUI(KC_2))))
#define S_G_A_C_N3 LCTL(LSFT(LALT(LGUI(KC_3))))
#define S_G_A_C_N4 LCTL(LSFT(LALT(LGUI(KC_4))))
#define S_G_A_C_N5 LCTL(LSFT(LALT(LGUI(KC_5))))
#define S_G_A_C_N6 LCTL(LSFT(LALT(LGUI(KC_6))))
#define S_G_A_C_N7 LCTL(LSFT(LALT(LGUI(KC_7))))
#define S_G_A_C_N8 LCTL(LSFT(LALT(LGUI(KC_8))))
#define S_G_A_C_N9 LCTL(LSFT(LALT(LGUI(KC_9))))
#define S_G_A_C_M  LCTL(LSFT(LALT(LGUI(KC_M))))
#define S_G_A_C_O  LCTL(LSFT(LALT(LGUI(KC_O))))

// Helper macro
#define LSG_A(kc) LCTL(LALT(LSFT(LGUI(kc)))) // If you need this form, otherwise replace inline

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAC] = LAYOUT_split_3x6_3(
     //,------------------------------------------------------------.            .----------------------------------------------------------.
        KC_LSFT, KC_Q,    KC_W,    KC_F,       KC_P,        KC_B,                 KC_J,       KC_L,       KC_U,    KC_Y,    KC_BSLS, KC_RSFT,
     //|--------+--------+--------+-----------+------------+--------|            |-----------+-----------+--------+--------+--------+--------|
        KC_TAB,  MT_LC_A, MT_LA_R, MT_LG_S,    MT_LS_T,     KC_G,                 KC_M,       MT_RS_N,    MT_RG_E, MT_RA_I, MT_RC_O, KC_RSFT,
     //|--------+--------+--------+-----------+------------+--------|            |-----------+-----------+--------+--------+--------+--------|
        KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_D,        KC_V,                 KC_K,       KC_H,       KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
     //|--------+--------+--------+-----------+------------+--------|            |-----------+-----------+--------+--------+--------+--------|
                                   LT_WIN_ESC, LT_NUM_BSPC, LT_FUN_TAB,           LT_NAV_RET, LT_SYM_SPC, MT_RG_DEL
                                //`------------------------------------'         `---------------------------------'
),

[_SYM] = LAYOUT_split_3x6_3(
    //,----------------------------------------------------------.      .--------------------------------------------------------.
        KC_LSFT, KC_GRAVE, KC_QUOTE, KC_DQUO,  KC_CIRC,  KC_LT,          KC_GT,   KC_EXLM,  KC_AMPR,  KC_PIPE,  KC_QUES,  KC_RSFT,
    //|---------+--------+---------+--------+---------+----------|      |--------+---------+---------+---------+--------+--------|
        KC_TAB,  MT_LC_AS, MT_LA_RS, MT_LG_SS, MT_LS_TS, KC_PAST,        KC_TILD, MT_RS_NS, MT_RG_ES, MT_RA_IS, MT_RC_OS, KC_RSFT,
    //|---------+--------+---------+--------+---------+----------|      |--------+---------+---------+---------+--------+--------|
        KC_LSFT, KC_SLSH,  KC_UNDS,  KC_PERC,  KC_DLR,   KC_HASH,        KC_BSLS, KC_LBRC,  KC_COLN,  KC_SCLN,  KC_RBRC,  KC_RSFT,
    //|---------+--------+---------+--------+---------+----------|      |--------+---------+---------+---------+--------+--------|
                                     TO(_MAC), KC_BSPC,  KC_TAB,         KC_ENT,  KC_SPC,   MT_RG_DEL
                                  //`----------------------------'       `---------------------------'
),

[_NUM] = LAYOUT_split_3x6_3(
        KC_LSFT, KC_Q,        KC_PGUP,         KC_UP,           KC_PGDN,                  KC_B,           KC_PLUS, KC_7,    KC_8,         KC_9,         KC_EQUAL,KC_RSFT,
        KC_TAB,  LCTL_T(KC_A),LALT_T(KC_LEFT), LGUI_T(KC_DOWN), LSFT_T(KC_RIGHT),         KC_G, KC_0,     RSFT_T(KC_4),     RGUI_T(KC_5), RALT_T(KC_6), RCTL_T(KC_COMM), KC_RSFT,
        KC_LSFT, KC_Z,        KC_HOME,         KC_COMM, KC_END, KC_V,                     KC_MINS, KC_1,  KC_2,             KC_3,         KC_DOT,       KC_RSFT,

),

[_NAV] = LAYOUT_split_3x6_3(
        KC_LSFT, KC_Q,         KC_W,         KC_F,         KC_P,        KC_B,            KC_J,           KC_PGUP,         KC_UP,           KC_PGDN,          KC_SCLN,                KC_RSFT,
        KC_TAB,  LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T),KC_G,            LALT(KC_GRAVE), RSFT_T(KC_LEFT), RGUI_T(KC_DOWN), RALT_T(KC_RIGHT), RCTL_T(LALT(KC_GRAVE)), KC_RSFT,
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,        KC_V,            KC_K,           KC_HOME,         KC_COMM,         KC_END,           KC_SLSH,                KC_RSFT,
                                             TO(_MAC),     KC_BSPC,     KC_TAB,          KC_ENT,         KC_SPC,          MT_RG_DEL
),

[_FUN] = LAYOUT_split_3x6_3(
        KC_LSFT, KC_LSFT,  KC_LSFT,  KC_LSFT, KC_LSFT,  KC_VOLU,     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F15,  KC_RSFT,
        KC_TAB, LCTL_T(KC_BRIU),LALT_T(KC_MPRV),LGUI_T(KC_MPLY),LSFT_T(KC_MNXT),KC_MUTE, KC_F11,  RSFT_T(KC_F4),RGUI_T(KC_F5),RALT_T(KC_F6),RCTL_T(KC_F14), KC_RSFT,
        KC_LSFT, KC_BRID, KC_CAPS, KC_C,    KC_D,    KC_VOLD,     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F13,  KC_RSFT,
                                TO(_MAC), KC_BSPC, KC_TAB,        KC_ENT,  KC_SPC,  MT_RG_DEL
),

[_WIN] = LAYOUT_split_3x6_3(
        KC_LSFT, KC_Q,    LSG_A(KC_W), LSG_A(KC_F), LSG_A(KC_P), KC_B,        KC_PLUS, S_G_A_C_N7, S_G_A_C_N8, S_G_A_C_N9, KC_EQUAL,KC_RSFT,
        KC_LSFT, LCTL_T(KC_A),LSG_A(KC_R), LSG_A(KC_S), LSG_A(KC_T), KC_G,    S_G_A_C_M, S_G_A_C_N4, S_G_A_C_N5, S_G_A_C_N6, S_G_A_C_O, KC_RSFT,
        KC_LSFT, KC_Z,    KC_X,    LSG_A(KC_C), KC_D,    KC_V,        KC_MINS, S_G_A_C_N1, S_G_A_C_N2, S_G_A_C_N3, KC_DOT,  KC_RSFT,
                                   TO(_MAC), KC_BSPC, KC_TAB,        KC_ENT,  KC_SPC,  MT_RG_DEL
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_AT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AT);   // Send KC_AT on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(KC_PLUS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PLUS); // Send KC_PLUS on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN); // Send KC_LPRN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR); // Send KC_LCBR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR); // Send KC_RCBR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN); // Send KC_RPRN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}
