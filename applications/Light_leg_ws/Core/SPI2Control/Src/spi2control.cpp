#include "spi2control.hpp"

uint8_t HikariSPIControler::rgb2spi_array_output_TEST(uint8_t *input_RGBcolor){

    int i = INIT_VALUE_0;
    int j = INIT_VALUE_0;

    //! header frame: [32*1] + light signal frame: [32*30] + tail frame: [32*1] = 1024
    //! every light signal frame = 8bit (for lightness) + 
    //! 8bit (for BLUE color) + 8bit (for GREEN color) + 8bit (for RED color)
    uint8_t SPI_SDI_COLOR_ARRAY[1024] = {0};  
    uint8_t Convert_Array[8] = {bit7_check, bit6_check, bit5_check, bit4_check,
                                bit3_check, bit2_check, bit1_check, bit0_check};
    //convert RGB Value to SPI Array for transmitting data
    //High order first mover

    //fix the array, the lightness is set as 0xE0 ~ 0xFF
    // for(i = INIT_VALUE_0; i < 30; i++){
    //     // input_RGBcolor[0+(4*i)] += 0xE0;
    //     if(input_RGBcolor[0+(4*i)] >= 0xFF){
    //         input_RGBcolor[0+(4*i)] = 0xFF;
    //     }
    // }

    //header frame:
    for(i = INIT_VALUE_0; i < 32; i++){

        SPI_SDI_COLOR_ARRAY[i] = SDI_ZERO;
        // printk("%d,  %x   \r\n", i, SPI_SDI_COLOR_ARRAY[i]);
    }

    //light signal frame:
    for(j = INIT_VALUE_0; j < 30; j++){
        printk("***********  %d  **************  \r\n", j);
            //lightness convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+(32*(j+1))] = (((input_RGBcolor[0+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+(32*(j+1))]);
            }
            //blue convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+8+(32*(j+1))] = (((input_RGBcolor[3+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+8+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+8+(32*(j+1))]);
            }
            //green convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+16+(32*(j+1))] = (((input_RGBcolor[2+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+16+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+16+(32*(j+1))]);
            }
            //red convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+24+(32*(j+1))] = (((input_RGBcolor[1+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+24+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+24+(32*(j+1))]);
            }
    }
    printk("***********  end  ************** \r\n");

    //tail frame
    for(i = INIT_VALUE_0; i < 32; i++){

        SPI_SDI_COLOR_ARRAY[992+i] = SDI_ONE;
        // printk("%d,  %x   \r\n", 992+i, SPI_SDI_COLOR_ARRAY[992+i]);
    }

    hikarispiconfig->my_spi_init(spi1);
    hikarispiconfig->my_spi_write(spi1, SPI_SDI_COLOR_ARRAY, 1024);

    return MY_FUNC_OK;
}

void HikariSPIControler::test(uint8_t *input_RGBcolor){

    int i = INIT_VALUE_0;
    int j = INIT_VALUE_0;

    uint8_t SPI_SDI_COLOR_ARRAY[1024] = {0};  
    uint8_t Convert_Array[8] = {bit7_check, bit6_check, bit5_check, bit4_check,
                                bit3_check, bit2_check, bit1_check, bit0_check};

    for(j = INIT_VALUE_0; j < 32; j++){
        // printk("***********  %d  **************  \r\n", j);
            //lightness convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+(32*(j))] = (((input_RGBcolor[0+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+(32*(j+1))]);
            }
            //blue convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+8+(32*(j))] = (((input_RGBcolor[3+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+8+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+8+(32*(j+1))]);
            }
            //green convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+16+(32*(j))] = (((input_RGBcolor[2+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+16+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+16+(32*(j+1))]);
            }
            //red convertion
            for(i = INIT_VALUE_0; i < 8; i++){
                SPI_SDI_COLOR_ARRAY[i+24+(32*(j))] = (((input_RGBcolor[1+(4*j)] & Convert_Array[i]) == Convert_Array[i])?SDI_ONE:SDI_ZERO);
                // printk("%d,  %x   \r\n", (i+24+(32*(j+1))), SPI_SDI_COLOR_ARRAY[i+24+(32*(j+1))]);
            }
    }  

    hikarispiconfig->my_spi_init(spi1);
    hikarispiconfig->my_spi_write(spi1, SPI_SDI_COLOR_ARRAY, 1024);
}

void HikariSPIControler::fsm_state_power_on(){
    
    if((basic_timer_cnt <= 15)){
        hikarigpioconfig->pwm_as_sck_on();
        new_test(test_one);
	    hikarigpioconfig->pwm_as_sck_off();
    }else if(basic_timer_cnt >= 65){
        hikarigpioconfig->pwm_as_sck_on();
        new_test(clear_array);
	    hikarigpioconfig->pwm_as_sck_off();
    }

    // if(basic_timer_cnt > 20){
    //     basic_timer_cnt = 0;
    // }

}

void HikariSPIControler::new_test(uint8_t *input_RGBcolor){

    uint8_t SPI_SDI_COLOR_ARRAY[1056] = {0};

    for(int i =0; i < 1056; i++){
        SPI_SDI_COLOR_ARRAY[i] = input_RGBcolor[i];
    }

    hikarispiconfig->my_spi_write(spi1, SPI_SDI_COLOR_ARRAY, 1056);
}

void HikariSPIControler::my_spi_init(FSM_STATE fsm_state){

    hikarispiconfig->my_spi_init(spi1);
    fsm_state = FSM_STATE_POWER_ON;
}

void HikariSPIControler::update_light(FSM_STATE fsm_state){
    switch (fsm_state)
    {
        // case FSM_STATE_LOOP:
        //     /* code */

        //     break;
        case FSM_STATE_POWER_ON:
            /* code */
            fsm_state_power_on();
            break;
        // case FSM_STATE_POWER_OFF:
        //     /* code */
            
        //     break;
        default:
            break;
    }
}