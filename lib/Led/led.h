#ifndef LED_H
#define LED_H

#include <stdint.h>

#define MY_STACK_SIZE 1000

#define led_1 13
#define led_2 14
#define led_3 15
#define led_4 16

#define fast 200
#define medium 500
#define slow 1000
#define slow_2 2000

void Blink_LED(uint32_t pin, uint32_t delay);

#endif