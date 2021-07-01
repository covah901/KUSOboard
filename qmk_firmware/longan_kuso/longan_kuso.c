#include "longan_kuso.h"
#include "rgblight.h"

void keyboard_post_init_user(void) {
    AFIO->MAPR |= AFIO_PCF0_SWJ_CFG_NOJNTRST;
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse=true;
    rgblight_enable_noeeprom();
    rgblight_sethsv(255, 255, 255);
    rgblight_setrgb(RGB_ORANGE);
}

#if defined(BUSY_WAIT)
void matrix_output_unselect_delay(void) {
    for (int32_t i = 0; i < BUSY_WAIT_INSTRUCTIONS; i++) {
        __asm__ volatile("nop" ::: "memory");
    }
}
#endif
