#include "mgos.h"
#include "mgos_lcd_1602.h"

bool mgos_lcd_1602_init() {
  return true;
}

mgos_lcd_1602 *mgos_lcd_1602_create(int rs, int rw, int enable) {
  mgos_lcd_1602 *lcd = (mgos_lcd_1602 *) calloc(0, sizeof(mgos_lcd_1602));

  if (lcd) {
    lcd->rs = rs;
    lcd->rw = rw;
    lcd->enable = enable;

    // default values after reset
    lcd->display  = LCD_DISPLAY_OFF;
    lcd->cursor   = LCD_CURSOR_OFF;
    lcd->blinking = LCD_BLINKING_OFF;
  }

  LOG(LL_INFO, ("lcd_1602 has been created..."));

  return lcd;
}

void mgos_lcd_1602_destroy(mgos_lcd_1602 *lcd) {
  LOG(LL_INFO, ("lcd_1602 has been destroy..."));
}

bool set_display(mgos_lcd_1602 *, bool display) {
  if (display) {
    
  }
}
