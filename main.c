/**
 ******************************************************************************
 * @file           : main.c
 * @author         : none
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>
#include <stdbool.h>

#define USE_BSRR		true     
#define WORD_LENGTH     16               

uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;    // RCC_AHB1ENR - RCC AHB1 peripheral clock enable register
uint32_t *pGpioAModer = (uint32_t*)0x40020000;    // GPIOA_MODER - GPIO port mode register
uint32_t *pGpioAOdr   = (uint32_t*)0x40020014;    // GPIOA_ODR   - GPIO port output data register (r/w)
uint32_t *pGpioABsrr  = (uint32_t*)0x40020018;    // GPIOA_BSRR  - GPIO port bit set/reset register (high word = atomic reset, low word = atomic set)

void delay(int ms)
{
    while (ms-- > 0) {
        volatile int x = 5971;
        while (x-- > 0)
            __asm("nop");
    }
}

int main(void)
{
	*pRccAhb1enr |= (1 << 0);						// set bit 0 to enable bus for port A

	*pGpioAModer &= ~((1 << 10) | (1 << 11));	    // clear bit 10 and 11
	*pGpioAModer |= (1 << 10);					    // set bit 10 to make pin 5 an output

    /* Loop forever */
	while(1)
	{
		delay(200);
#if USE_BSRR == false
		*pGpioAOdr ^= (1 << 5);                     // toggle bit 5
#elif USE_BSRR == true
		if (((*pGpioAOdr >> 5) & 0x1) == 0)
		{
			*pGpioABsrr = (1 << 5);                 // set bit 5
		}
		else
		{
			*pGpioABsrr = (1 << (WORD_LENGTH + 5));          // clear bit 16 + 5
		}
#endif
	}
}
