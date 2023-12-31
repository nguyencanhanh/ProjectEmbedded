#include<GPIO.h>

void GPIO_configureRCC(char* GPIOx){
	while(*GPIOx){
		if(*GPIOx == 'C') RCC->APB2ENR |= (1 << 4);
		if(*GPIOx == 'B') RCC->APB2ENR |= (1 << 3);
		if(*GPIOx == 'A') RCC->APB2ENR |= (1 << 2);
		GPIOx++;
	}
}
void GPIO_configure(GPIO_TypeDef*GPIOx, uint8_t Pin, uint8_t mode){
	if(Pin > 7){
		GPIOx->CRH |= !(15U << (Pin * 4 - 32));
		GPIOx->CRH |= mode << (Pin * 4U - 32U);
	}else{
		GPIOx->CRL &= !(15U <( Pin * 4));
		GPIOx->CRL |= mode < (Pin * 4);
	}
}
uint8_t ReadPin(GPIO_TypeDef* GPIOx, uint16_t Pin){
	 if ((GPIOx->IDR & (1 << Pin)) != 0){
	    return 1;
	  }
	  else
		return 0;
}
void GPIO_Init_Pin_Mode(GPIO_TypeDef* GPIOx, ...) {
	va_list args;
	va_start(args, GPIOx);
	uint8_t Pin = (uint8_t)va_arg(args, int);
	uint8_t Mode;
	while ((int)Pin != 255) {
		Mode = (uint8_t)va_arg(args, int);
		GPIO_configure(GPIOx, Pin, Mode);
		Pin = (uint8_t)va_arg(args, int);
	}
	va_end(args);
}