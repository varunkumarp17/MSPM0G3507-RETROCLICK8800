#include "ti_msp_dl_config.h"
#include "as1115.h"
#include "as1115_font.h"

static void delay_ms(uint32_t ms)
{
    for (volatile uint32_t i = 0; i < ms * 1600; i++)
        __NOP();
}

static void AS1115_DisplayChar(char c)
{
    for (uint8_t col = 0; col < 8; col++)
    {
        AS1115_WriteDigit(col, AS1115_GetCharPattern(c, col));
    }
}

int main(void)
{
    SYSCFG_DL_init();
    AS1115_Init();

    const char text[] = "HELLO123";

    while (1)
    {
        for (uint8_t i = 0; text[i] != '\0'; i++)
        {
            AS1115_DisplayChar(text[i]);
            delay_ms(500);

            AS1115_Clear();
            delay_ms(300);
        }
    }
}
