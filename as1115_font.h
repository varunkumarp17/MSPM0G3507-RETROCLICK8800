#ifndef AS1115_FONT_H
#define AS1115_FONT_H

#include <stdint.h>

/* Get column data (0–7) for a given character */
uint8_t AS1115_GetCharPattern(char c, uint8_t column);

#endif
