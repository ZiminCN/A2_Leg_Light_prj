#include "spi2control.hpp"

uint8_t HikariSPIControler::rgb2spi_array_output(SDI_COLOR_STRUCT input_RGBcolor){

    int i = INIT_VALUE_0;
    uint8_t SPI_SDI_COLOR_ARRAY[24];
    uint8_t Convert_Array[8] = {bit7_check, bit6_check, bit5_check, bit4_check,
                                bit3_check, bit2_check, bit1_check, bit0_check};
    //convert RGB Value to SPI Array for transmitting data
    //High order first mover
    for(i = INIT_VALUE_0; i < 8; i++){
        SPI_SDI_COLOR_ARRAY[i] = ((input_RGBcolor.R_Value & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO;
    }
    for(i = 8; i < 16; i++){
        SPI_SDI_COLOR_ARRAY[i] = ((input_RGBcolor.G_Value & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO;
    }
    for(i = 16; i < 24; i++){
        SPI_SDI_COLOR_ARRAY[i] = ((input_RGBcolor.B_Value & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO;
    }

    hikarispiconfig->my_spi_init(spi1);
    hikarispiconfig->my_spi_write(spi1, SPI_SDI_COLOR_ARRAY, sizeof(SPI_SDI_COLOR_ARRAY));

    return MY_FUNC_OK;
}

uint8_t HikariSPIControler::rgb2spi_array_output_TEST(uint8_t *input_RGBcolor){

    int i = INIT_VALUE_0;
    int j = INIT_VALUE_0;
    uint8_t SPI_SDI_COLOR_ARRAY[720];
    uint8_t Convert_Array[8] = {bit7_check, bit6_check, bit5_check, bit4_check,
                                bit3_check, bit2_check, bit1_check, bit0_check};
    //convert RGB Value to SPI Array for transmitting data
    //High order first mover

    for(j = INIT_VALUE_0; j < 30; j++){
        for(i = INIT_VALUE_0; i < 8; i++){
            SPI_SDI_COLOR_ARRAY[i+(24*j)] = ((input_RGBcolor[0+(3*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO;
        }
        for(i = 8; i < 16; i++){
            SPI_SDI_COLOR_ARRAY[i+(24*j)] = ((input_RGBcolor[1+(3*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO;
        }
        for(i = 16; i < 24; i++){
            SPI_SDI_COLOR_ARRAY[i+(24*j)] = ((input_RGBcolor[2+(3*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO;
        }
    }
    hikarispiconfig->my_spi_init(spi1);
    hikarispiconfig->my_spi_write(spi1, SPI_SDI_COLOR_ARRAY, sizeof(SPI_SDI_COLOR_ARRAY));

    return MY_FUNC_OK;
}

uint8_t HikariSPIControler::nomal_test_spi_write(uint8_t input_rgbcolor[], size_t len){

    hikarispiconfig->my_spi_init(spi1);
    hikarispiconfig->my_spi_write(spi1, input_rgbcolor, len);

    return MY_FUNC_OK;
}