#include <zephyr.h>
#include <drivers/gpio.h>
#include <device.h>
#include <ir.h>

volatile uint8_t ir_value = 0;

static const struct device *gpio_ct_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));

void read_ir_data(uint8_t pin)
{
    if (!device_is_ready(gpio_ct_dev))
    {
        return;
    }
    int ret;
    ret = gpio_pin_configure(gpio_ct_dev, pin, GPIO_INPUT);
    if (ret != 0)
    {
        return;
    }
    while (1)
    {
        ir_value = gpio_pin_get(gpio_ct_dev, pin);
        if (ir_value == 1)
        {

            if (pin == RIGHT_IR_PIN)
            {
                printk("RIGHT SENSOR : black line detected !\n");
            }
            else
            {
                printk("LEFT SENSOR : black line detected !\n");
            }
        }
        else
        {

            if (pin == RIGHT_IR_PIN)
            {
                printk("RIGHT SENSOR : white line detected !\n");
            }
            else
            {
                printk("LEFT SENSOR : white line detected !\n");
            }
        }

        k_msleep(100);
    }
}