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
#define MT_RG_E MT(MOD_LGUI, KC_E)
#define MT_RA_I MT(MOD_RALT, KC_I)
#define MT_RC_O MT(MOD_RCTL, KC_O)

// Basic placeholders retain QMK tap-hold handling. The hook sends the full tap code.
#define MT_LC_AS LCTL_T(KC_F16)
#define MT_LA_RS LALT_T(KC_MINUS)
#define MT_LG_SS LGUI_T(KC_F17)
#define MT_LS_TS LSFT_T(KC_EQUAL)
#define MT_RS_NS RSFT_T(KC_F18)
#define MT_RG_ES LGUI_T(KC_F19)
#define MT_RA_IS RALT_T(KC_F20)
#define MT_RC_OS RCTL_T(KC_F21)
#define MT_WORD_RIGHT RCTL_T(KC_F22)

// Hyper key definition
#define MT_RG_DEL ALL_T(KC_DEL) // Hyper + Delete

// Layer-tap definitions
#define LT_WIN_ESC LT(_WIN, KC_ESC)
#define LT_NUM_BSPC LT(_NUM, KC_BSPC)
#define LT_FUN_TAB LT(_FUN, KC_TAB)
#define LT_NAV_RET LT(_NAV, KC_ENT)
#define LT_SYM_SPC LT(_SYM, KC_SPC)

// Window digits use layer-tap placeholders for custom tap and hold chords.
// ZMK uses raw integers in these holds; use the intended digit keycodes here.
#define S_G_A_C_N1 LT(_MAC, KC_1)
#define S_G_A_C_N2 LT(_MAC, KC_2)
#define S_G_A_C_N3 LT(_MAC, KC_3)
#define S_G_A_C_N4 LT(_MAC, KC_4)
#define S_G_A_C_N5 LT(_MAC, KC_5)
#define S_G_A_C_N6 LT(_MAC, KC_6)
#define S_G_A_C_N7 LT(_MAC, KC_7)
#define S_G_A_C_N8 LT(_MAC, KC_8)
#define S_G_A_C_N9 LT(_MAC, KC_9)
#define S_G_A_C_M  LCTL(LSFT(LALT(LGUI(KC_M))))
#define S_G_A_C_O  LCTL(LSFT(LALT(LGUI(KC_O))))

// Helper macro
#define LSG_A(kc) LSFT(LALT(LGUI(kc)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAC] = LAYOUT_split_3x6_3(
    KC_LSFT,  KC_Q,     KC_W,     KC_F,     KC_P,          KC_B,  KC_J,  KC_L,          KC_U,     KC_Y,     KC_BSLS,  KC_RSFT,
    KC_TAB,   MT_LC_A,  MT_LA_R,  MT_LG_S,  MT_LS_T,       KC_G,  KC_M,  MT_RS_N,       MT_RG_E,  MT_RA_I,  MT_RC_O,  KC_RSFT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     RGUI_T(KC_D),  KC_V,  KC_K,  RGUI_T(KC_H),  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    LT_WIN_ESC, LT_NUM_BSPC, LT_FUN_TAB, LT_NAV_RET, LT_SYM_SPC, MT_RG_DEL
),

[_SYM] = LAYOUT_split_3x6_3(
    KC_LGUI,  KC_GRAVE,  KC_QUOTE,  KC_DQUO,   KC_CIRC,   KC_LT,    KC_GT,    KC_EXLM,   KC_AMPR,   KC_PIPE,   KC_QUES,   KC_RGUI,
    KC_LALT,  MT_LC_AS,  MT_LA_RS,  MT_LG_SS,  MT_LS_TS,  KC_ASTR,  KC_TILD,  MT_RS_NS,  MT_RG_ES,  MT_RA_IS,  MT_RC_OS,  KC_RALT,
    KC_LCTL,  KC_SLSH,   KC_UNDS,   KC_PERC,   KC_DLR,    KC_HASH,  KC_BSLS,  KC_LBRC,   KC_COLN,   KC_SCLN,   KC_RBRC,   KC_RCTL,
    LT(_MAC, KC_ESC), KC_BSPC, KC_TAB, KC_ENT, KC_SPC, RGUI_T(KC_DEL)
),

[_NUM] = LAYOUT_split_3x6_3(
    KC_LSFT,  KC_Q,          KC_W,             KC_UP,            KC_P,              KC_B,  KC_PLUS,  KC_7,          KC_8,          KC_9,          KC_EQUAL,         KC_RSFT,
    KC_TAB,   LCTL_T(KC_A),  LALT_T(KC_LEFT),  LGUI_T(KC_DOWN),  LSFT_T(KC_RIGHT),  KC_G,  KC_0,     RSFT_T(KC_4),  LGUI_T(KC_5),  RALT_T(KC_6),  RCTL_T(KC_COMM),  KC_RSFT,
    KC_LSFT,  KC_Z,          KC_X,             KC_C,             KC_D,              KC_V,  KC_MINS,  KC_1,          KC_2,          KC_3,          KC_DOT,           KC_RSFT,
    LT(_MAC, KC_ESC), KC_BSPC, KC_TAB, KC_ENT, KC_0, RGUI_T(KC_DEL)
),

[_NAV] = LAYOUT_split_3x6_3(
    KC_LSFT,  KC_Q,          KC_W,          KC_F,          KC_P,          KC_B,  KC_J,           KC_PGUP,          KC_UP,            KC_PGDN,           KC_SCLN,        KC_RSFT,
    KC_TAB,   LCTL_T(KC_A),  LALT_T(KC_R),  LGUI_T(KC_S),  LSFT_T(KC_T),  KC_G,  LALT(KC_LEFT),  RSFT_T(KC_LEFT),  LGUI_T(KC_DOWN),  RALT_T(KC_RIGHT),  MT_WORD_RIGHT,  KC_RSFT,
    KC_LSFT,  KC_Z,          KC_X,          KC_C,          KC_D,          KC_V,  KC_K,           KC_HOME,          KC_COMM,          KC_END,            KC_SLSH,        KC_RSFT,
    LT(_MAC, KC_ESC), KC_BSPC, KC_TAB, KC_ENT, KC_SPC, RGUI_T(KC_DEL)
),

[_FUN] = LAYOUT_split_3x6_3(
    KC_LSFT,  KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_VOLU,  KC_F12,  KC_F7,          KC_F8,          KC_F9,          KC_F15,          KC_RSFT,
    KC_TAB,   LCTL_T(KC_BRIU),  LALT_T(KC_MPRV),  LGUI_T(KC_MPLY),  LSFT_T(KC_MNXT),  KC_MUTE,  KC_F11,  RSFT_T(KC_F4),  LGUI_T(KC_F5),  RALT_T(KC_F6),  RCTL_T(KC_F14),  KC_RSFT,
    KC_LSFT,  KC_BRID,          KC_CAPS,          KC_C,             KC_D,             KC_VOLD,  KC_F10,  KC_F1,          KC_F2,          KC_F3,          KC_F13,          KC_RSFT,
    LT(_MAC, KC_ESC), KC_BSPC, KC_TAB, KC_ENT, KC_SPC, RGUI_T(KC_DEL)
),

[_WIN] = LAYOUT_split_3x6_3(
    KC_LSFT,  KC_Q,          LSG_A(KC_W),  LSG_A(KC_F),  LSG_A(KC_P),  KC_B,  KC_PLUS,    S_G_A_C_N7,  S_G_A_C_N8,  S_G_A_C_N9,  KC_EQUAL,   KC_RSFT,
    KC_LSFT,  LCTL_T(KC_A),  LSG_A(KC_R),  LSG_A(KC_S),  LSG_A(KC_T),  KC_G,  S_G_A_C_M,  S_G_A_C_N4,  S_G_A_C_N5,  S_G_A_C_N6,  S_G_A_C_O,  KC_RSFT,
    KC_LSFT,  KC_Z,          KC_X,         LSG_A(KC_C),  KC_D,         KC_V,  KC_MINS,    S_G_A_C_N1,  S_G_A_C_N2,  S_G_A_C_N3,  KC_DOT,     KC_RSFT,
    LT(_MAC, KC_ESC), KC_BSPC, KC_TAB, KC_ENT, KC_SPC, RGUI_T(KC_DEL)
)
};


const uint16_t PROGMEM caps_combo[] = {LT_FUN_TAB, LT_NAV_RET, COMBO_END};
combo_t key_combos[] = {COMBO(caps_combo, KC_CAPS)};

static bool is_window_digit(uint16_t keycode) {
    return keycode >= S_G_A_C_N1 && keycode <= S_G_A_C_N9;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_LAYER_TAP(keycode) ? 200 : TAPPING_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return is_window_digit(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t output;
    if (is_window_digit(keycode)) {
        uint16_t digit = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
        output = record->tap.count ? LCA(digit) : HYPR(digit);
    } else {
        if (!record->tap.count) {
            return true;
        }
        switch (keycode) {
            case MT_LC_AS: output = KC_AT; break;
            case MT_LG_SS: output = KC_PLUS; break;
            case MT_RS_NS: output = KC_LPRN; break;
            case MT_RG_ES: output = KC_LCBR; break;
            case MT_RA_IS: output = KC_RCBR; break;
            case MT_RC_OS: output = KC_RPRN; break;
            case MT_WORD_RIGHT: output = LALT(KC_RIGHT); break;
            default: return true;
        }
    }
    // Keep the full chord pressed until release, including both tap and hold paths.
    if (record->event.pressed) {
        register_code16(output);
    } else {
        unregister_code16(output);
    }
    return false;
}
