/*
 * Copyright 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
* Notes:
* This is a free time project to improve my own knowledge.
*
* (1) Busy Flag (BF)
* When the busy flag is 1, the HD44780U is in the internal operation mode, and the next instruction will not
* be accepted. When RS = 0 and R/W = 1 (Table 1), the busy flag is output to DB7. The next instruction
* must be written after ensuring that the busy flag is 0.
*
* (2) An internal reset circuit automatically initializes the HD44780U when the power is turned on. The
* following instructions are executed during the initialization. The busy flag (BF) is kept in the busy state
* until the initialization ends (BF = 1). The busy state lasts for 10 ms after VCC rises to 4.5 V.
*   1. Display clear
*   2. Function set:
*     DL = 1; 8-bit interface data
*     N = 0; 1-line display
*     F = 0; 5 ´ 8 dot character font
*   3. Display on/off control:
*     D = 0; Display off
*     C = 0; Cursor off
*     B = 0; Blinking off
*   4. Entry mode set:
*     I/D = 1; Increment by 1
*     S = 0; No shift
*/

#ifndef __MGOS_LCD_1602__
#define __MGOS_LCD_1602__

#include "mgos.h"

// INSTRUCTIONS
#define LCD_CLEAR_DISPLAY   0x01
#define LCD_RETURN_HOME     0x02
#define LCD_SET_ENTRY_MODE  0x03
#define LCD_DISPLAY_OFF     0x00
#define LCD_SET_CGRAM       0x40
#define LCD_SET_DDRAM       0x80

#define LCD_DISPLAY_ON      0x04
#define LCD_DISPLAY_OFF     0x00
#define LCD_CURSOR_ON       0x02
#define LCD_CURSOR_OFF      0x00
#define LCD_BLINKING_ON     0x01
#define LCD_BLINKING_OFF    0x00

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mgos_lcd_1602_t {
  int rs;
  int rw;
  int enable;
  char *display;
  char *cursor;
  char *blinking;
} mgos_lcd_1602;

mgos_lcd_1602 *mgos_lcd_1602_create(int rs, int rw, int enable);
void           mgos_lcd_1602_destroy(mgos_lcd_1602 *);

// control functions
bool set_display(mgos_lcd_1602 *, bool);
bool set_cursor(mgos_lcd_1602 *, bool);
bool set_blinking(mgos_lcd_1602 *, bool);

// these function shold be used as private functions.
void send_command(mgos_lcd_1602 *, char *cmd);
void send_instruction(mgos_lcd_1602 *, char *inst);

#ifdef __cplusplus
}
#endif

#endif // __MGOS_LCD_1602__
