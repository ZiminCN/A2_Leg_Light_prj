#ifndef __SPI2CONTROL_HPP
#define __SPI2CONTROL_HPP

#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include "para_def.h"
#include "spi_func.hpp"
#include "gpio_func.hpp"

extern int basic_timer_cnt;
extern uint8_t clear_array[];
extern uint8_t test_1[];
extern uint8_t test_2[];
extern uint8_t test_3[];
extern uint8_t test_4[];
extern uint8_t test_5[];
extern uint8_t test_6[];
extern uint8_t test_7[];
extern uint8_t test_8[];
extern uint8_t test_9[];
extern uint8_t test_10[];
extern uint8_t test_11[];
extern uint8_t test_12[];
extern uint8_t test_13[];
extern uint8_t test_14[];
extern uint8_t test_15[];
extern uint8_t test_16[];
extern uint8_t test_17[];
extern uint8_t test_18[];
extern uint8_t test_19[];
extern uint8_t test_20[];
extern uint8_t test_21[];
extern uint8_t test_22[];
extern uint8_t test_23[];
extern uint8_t test_24[];
extern uint8_t test_25[];
extern uint8_t test_26[];
extern uint8_t test_27[];
extern uint8_t test_28[];
extern uint8_t test_29[];
extern uint8_t test_30[];
extern uint8_t cleartest_array[];

extern uint8_t szero[];
class HikariSPIControler {

    HikariSPIConfig *hikarispiconfig;
	HikariGPIOConfig *hikarigpioconfig;
    public:
        static HikariSPIControler *GetInstance() { return &_sInstance;}
        void test(uint8_t *input_RGBcolor);
        void new_test(uint8_t *input_RGBcolor);
        void my_spi_init(FSM_STATE fsm_state);
        void update_light(FSM_STATE fsm_state);
        void light_as_array(uint8_t *input_RGBcolor);

    private:
        static HikariSPIControler _sInstance;
        void fsm_state_power_on();
        void fsm_state_clear();
        bool lightingornot;
};

#endif //__SPI2CONTROL_HPP