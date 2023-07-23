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
        uint8_t rgb2spi_array_output_TEST(uint8_t *input_RGBcolor);
        void test(uint8_t *input_RGBcolor);
        void new_test(uint8_t *input_RGBcolor);
    private:
        static HikariSPIControler _sInstance;
};

#endif //__SPI2CONTROL_HPP