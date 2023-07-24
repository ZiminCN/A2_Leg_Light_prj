#ifndef __SPI2CONTROL_HPP
#define __SPI2CONTROL_HPP

#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include "para_def.h"
#include "spi_func.hpp"
#include "gpio_func.hpp"
// #include "default_light_effect.h"

extern int basic_timer_cnt;
extern uint8_t clear_array[];
extern uint8_t test_one[];

class HikariSPIControler {

    HikariSPIConfig *hikarispiconfig;
	HikariGPIOConfig *hikarigpioconfig;
    public:
        static HikariSPIControler *GetInstance() { return &_sInstance;}
        uint8_t rgb2spi_array_output_TEST(uint8_t *input_RGBcolor);
        void test(uint8_t *input_RGBcolor);
        void new_test(uint8_t *input_RGBcolor);
        void my_spi_init(FSM_STATE fsm_state);
        void update_light(FSM_STATE fsm_state);
    private:
        static HikariSPIControler _sInstance;
        void fsm_state_power_on();
        bool lightingornot;
};

#endif //__SPI2CONTROL_HPP