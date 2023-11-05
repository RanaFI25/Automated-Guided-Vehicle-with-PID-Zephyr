#include <zephyr.h>
#include <drivers/gpio.h>
#include <device.h>
#include <led.h>
#include <ir.h>

K_THREAD_DEFINE(Blink_LED1_ID, MY_STACK_SIZE, Blink_LED, led_1, fast, NULL, 1, 0, 0);
K_THREAD_DEFINE(Blink_LED2_ID, MY_STACK_SIZE, Blink_LED, led_2, fast, NULL, 1, 0, 0);
K_THREAD_DEFINE(Blink_LED3_ID, MY_STACK_SIZE, Blink_LED, led_3, fast, NULL, 1, 0, 0);
K_THREAD_DEFINE(Blink_LED4_ID, MY_STACK_SIZE, Blink_LED, led_4, fast, NULL, 1, 0, 0);
K_THREAD_DEFINE(LEFT_IR_SENSOR, MY_STACK_SIZE, read_ir_data, LEFT_IR_PIN, NULL, NULL, 0, 0, 0);
K_THREAD_DEFINE(RIGHT_IR_SENSOR, MY_STACK_SIZE, read_ir_data, RIGHT_IR_PIN, NULL, NULL, 0, 0, 0);
