#include <stm32f1xx.h>
#include <stdarg.h>

#define BeginGPIO(...) GPIO_Init_Pin_Mode(__VA_ARGS__, 255)

#define GPIOA_ON(pin)  \
    do { \
        GPIOA->BSRR |= (1U << (pin)); \
    } while(0)

#define GPIOA_OFF(pin)  \
    do { \
        GPIOA->BSRR |= (1U << (pin + 16)); \
    } while(0)

#define GPIOA_TOGGLE(pin)  \
    do { \
        GPIOA->ODR ^= (1U << (pin)); \
    } while(0)

#define GPIOB_ON(pin)  \
    do { \
        GPIOB->BSRR |= (1U << (pin)); \
    } while(0)

#define GPIOB_OFF(pin)  \
    do { \
        GPIOB->BSRR |= (1U << (pin + 16)); \
    } while(0)

#define GPIOB_TOGGLE(pin)  \
    do { \
        GPIOB->ODR ^= (1U << (pin)); \
    } while(0)

#define GPIOC_ON(pin)  \
    do { \
        GPIOC->BSRR |= (1U << (pin)); \
    } while(0)

#define GPIOC_OFF(pin)  \
    do { \
        GPIOC->BSRR |= (1U << (pin + 16)); \
    } while(0)

#define GPIOC_TOGGLE(pin)  \
    do { \
        GPIOC->ODR ^= (1U << (pin)); \
    } while(0)


void GPIO_configureRCC(char* GPIOx);
void GPIO_configure(GPIO_TypeDef*GPIOx, uint8_t Pin, uint8_t mode);
uint8_t ReadPin(GPIO_TypeDef* GPIOx, uint16_t Pin);
void GPIO_Init_Pin_Mode(GPIO_TypeDef* GPIOx, ...);
