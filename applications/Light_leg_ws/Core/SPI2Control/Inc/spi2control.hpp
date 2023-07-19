#ifndef __SPI2CONTROL_HPP
#define __SPI2CONTROL_HPP

#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include "para_def.h"
#include "spi_func.hpp"

class HikariSPIControler {

    HikariSPIConfig *hikarispiconfig;
    public:
        static HikariSPIControler *GetInstance() { return &_sInstance;}
        void test();
        uint8_t rgb2spi_array_output(SK6812_SDI_COLOR_STRUCT input_RGBcolor);
        uint8_t rgb2spi_array_output_TEST(uint8_t input_rgbcolor[]);
        uint8_t nomal_test_spi_write(uint8_t input_rgbcolor[]);
    private:
        static HikariSPIControler _sInstance;
};

#endif //__SPI2CONTROL_HPP