#include <led.h>
#include <zephyr.h>
#include <drivers/gpio.h>
#include <device.h>

static const struct device *gpio_ct_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));

void Blink_LED(uint32_t pin, uint32_t delay)
{

    if (!device_is_ready(gpio_ct_dev))
    {
        return;
    }
    int ret;
    ret = gpio_pin_configure(gpio_ct_dev, pin, GPIO_OUTPUT_ACTIVE);
    if (ret != 0)
    {
        return;
    }
    while (true)
    {
        ret = gpio_pin_set_raw(gpio_ct_dev, pin, 0); // Set
        k_msleep(delay);

        ret = gpio_pin_set_raw(gpio_ct_dev, pin, 1); // Clear
        k_msleep(delay);
    }
}
