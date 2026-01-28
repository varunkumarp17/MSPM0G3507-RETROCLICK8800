#ifndef AS1115_H
#define AS1115_H

#include <stdint.h>

// AS1115 registers
#define AS1115_REG_DIGIT0   0x01
#define AS1115_REG_SHUTDOWN 0x0C

void AS1115_Init(void);
void AS1115_SetBrightness(uint8_t level);
void AS1115_Clear(void);
void AS1115_WriteDigit(uint8_t digit, uint8_t value);

#endif
