#include "mgos.h"
#include "mgos_lcd_1602.h"

mgos_lcd_1602 *mgos_lcd_1602_init(int rs, int rw, int enable) {
  mgos_lcd_1602 *lcd = calloc(0, sizeof(mgos_lcd_1602));

  lcd->rs = rs;
  lcd->rw = rw;
  lcd->enable = enable;

  LOG(LL_INFO, ("lcd_1602 has been created..."));

  return lcd;
}

void mgos_lcd_1602_destroy(mgos_lcd_1602 *lcd) {
  if (lcd)
    free(lcd);
  LOG(LL_INFO, ("lcd_1602 has been destroy..."));
}
