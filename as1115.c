#include "as1115.h"
#include "ti_msp_dl_config.h"

#define AS1115_ADDR 0x00

static void AS1115_I2C_Write(uint8_t reg, uint8_t data)
{
    uint8_t txBuf[2] = { reg, data };
    DL_I2C_fillControllerTXFIFO(I2C1, txBuf, 2);
    DL_I2C_startControllerTransfer(I2C1, AS1115_ADDR,
        DL_I2C_CONTROLLER_DIRECTION_TX, 2);

    while (DL_I2C_getControllerStatus(I2C1) &
           DL_I2C_CONTROLLER_STATUS_BUSY);
}

void AS1115_Init(void)
{
    AS1115_I2C_Write(0x09, 0x00); // No decode
    AS1115_I2C_Write(0x0A, 0x0F); // Brightness
    AS1115_I2C_Write(0x0B, 0x07); // Scan all digits
    AS1115_I2C_Write(0x0C, 0x01); // Normal mode
    AS1115_I2C_Write(0x0F, 0x00); // Test off
}

void AS1115_SetBrightness(uint8_t level)
{
    if (level > 0x0F) level = 0x0F;
    AS1115_I2C_Write(0x0A, level);
}

void AS1115_Clear(void)
{
    for (uint8_t i = 0; i < 8; i++)
        AS1115_I2C_Write(AS1115_REG_DIGIT0 + i, 0x00);
}

void AS1115_WriteDigit(uint8_t digit, uint8_t value)
{
    if (digit < 8)
        AS1115_I2C_Write(AS1115_REG_DIGIT0 + digit, value);
}
