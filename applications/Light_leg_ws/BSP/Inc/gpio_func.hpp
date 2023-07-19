#ifndef __GPIO_FUNC_HPP
#define __GPIO_FUNC_HPP

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/devicetree.h>
#include "para_def.h"

#define LED_A_NODE DT_ALIAS(boardleda)
#define LED_B_NODE DT_ALIAS(boardledb)
#define LED_C_NODE DT_ALIAS(boardledc)

static const struct gpio_dt_spec BOARD_LED_A = GPIO_DT_SPEC_GET(LED_A_NODE, gpios);
static const struct gpio_dt_spec BOARD_LED_B = GPIO_DT_SPEC_GET(LED_B_NODE, gpios);
static const struct gpio_dt_spec BOARD_LED_C = GPIO_DT_SPEC_GET(LED_C_NODE, gpios);

class HikariGPIOConfig {
    public:
        static HikariGPIOConfig *GetInstance() {return &_sInstance;}
        void test_led();
        uint8_t board_led_init();
        void board_led_a_on();
        void board_led_a_off();
        void board_led_b_on();
        void board_led_b_off();
        void board_led_c_on();
        void board_led_c_off();

    private:
        static HikariGPIOConfig _sInstance;
};

#endif //__GPIO_FUNC_HPP