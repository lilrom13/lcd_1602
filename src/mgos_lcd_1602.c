#include "mgos.h"
#include "mgos_lcd_1602.h"

mgos_lcd_1602 *init_lcd_1602(int rs, int rw, int enable) {
  mgos_lcd_1602 *lcd = calloc(0, sizeof(mgos_lcd_1602));

  lcd->rs = rs;
  lcd->rw = rw;
  lcd->enable = enable;

  return lcd;
}

void destroy_lcd_1602(mgos_lcd_1602 *lcd) {
  if (lcd)
    free(lcd);
}
