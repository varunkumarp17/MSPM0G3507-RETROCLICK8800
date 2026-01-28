#include "ti_msp_dl_config.h"
#include "as1115.h"

static void delay_ms(uint32_t ms)
{
    for (volatile uint32_t i = 0; i < (ms * 1600); i++)
    {
        __NOP();
    }
}

int main(void)
{
    SYSCFG_DL_init();     // Initialize system and peripherals
    AS1115_Init();        // Initialize AS1115 driver

    while (1)
    {
        /* Turn ON all LEDs */
        for (uint8_t digit = 0; digit < 8; digit++)
        {
            AS1115_WriteDigit(digit, 0xFF);
        }
        delay_ms(500);

        /* Turn OFF all LEDs */
        AS1115_Clear();
        delay_ms(500);
    }
}
