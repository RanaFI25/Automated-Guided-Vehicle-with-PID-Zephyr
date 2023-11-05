#ifndef IR_H
#define IR_H

#include <stdint.h>

#define RIGHT_IR_PIN 26
#define LEFT_IR_PIN 27

extern volatile uint8_t ir_value;

void read_ir_data(uint8_t pin);

#endif