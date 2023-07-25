#include "spi2control.hpp"
void HikariSPIControler::test(uint8_t *input_RGBcolor){

    int i = INIT_VALUE_0;
    int j = INIT_VALUE_0;

    uint8_t SPI_SDI_COLOR_ARRAY[1056] = {0};  
    uint8_t Convert_Array[8] = {bit7_check, bit6_check, bit5_check, bit4_check,
                                bit3_check, bit2_check, bit1_check, bit0_check};

    //header frame
    // for(i = INIT_VALUE_0; i < 64; i++){
    //     SPI_SDI_COLOR_ARRAY[i] = SDI_ZERO;
    // }

    //light data frame
    for(i = INIT_VALUE_0; i < 30; i++){
        
        for(j = INIT_VALUE_0; j < 8; j++){
            SPI_SDI_COLOR_ARRAY[64+j+(i*32)] = ((((input_RGBcolor[0+(i*4)])&Convert_Array[j])==Convert_Array[j])?SDI_ONE:SDI_ZERO);
        }
        for(j = INIT_VALUE_0; j < 8; j++){
            SPI_SDI_COLOR_ARRAY[64+8+j+(i*32)] = ((((input_RGBcolor[3+(i*4)])&Convert_Array[j])==Convert_Array[j])?SDI_ONE:SDI_ZERO);
        }
        for(j = INIT_VALUE_0; j < 8; j++){
            SPI_SDI_COLOR_ARRAY[64+16+j+(i*32)] = ((((input_RGBcolor[2+(i*4)])&Convert_Array[j])==Convert_Array[j])?SDI_ONE:SDI_ZERO);
        }
        for(j = INIT_VALUE_0; j < 8; j++){
            SPI_SDI_COLOR_ARRAY[64+24+j+(i*32)] = ((((input_RGBcolor[1+(i*4)])&Convert_Array[j])==Convert_Array[j])?SDI_ONE:SDI_ZERO);
        }
    }

    for(i = INIT_VALUE_0; i < 32; i++){
        SPI_SDI_COLOR_ARRAY[1024+i] = SDI_ONE;
    }

    //tail frame

    // hikarispiconfig->my_spi_init(spi1);
    hikarispiconfig->my_spi_write(spi1, SPI_SDI_COLOR_ARRAY, 1056);
}

void HikariSPIControler::light_as_array(uint8_t *input_RGBcolor){

    hikarigpioconfig->pwm_as_sck_on();
    test(input_RGBcolor);
    hikarigpioconfig->pwm_as_sck_off();
}

void HikariSPIControler::fsm_state_clear(){

    if((basic_timer_cnt >= 1) && (basic_timer_cnt <= 2)){
        hikarigpioconfig->pwm_as_sck_on();
        test(cleartest_array);
        // test(clear_array);
	    hikarigpioconfig->pwm_as_sck_off();
    }else if((basic_timer_cnt >= 65) && (basic_timer_cnt <= 66)){
        hikarigpioconfig->pwm_as_sck_on();
        // test(cleartest_array);
        test(clear_array);
	    hikarigpioconfig->pwm_as_sck_off();
    }
}

void HikariSPIControler::fsm_state_power_on(){

    if((basic_timer_cnt >= 1) && (basic_timer_cnt <= 2)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_1);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 6) && (basic_timer_cnt <= 10)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_2);
	    hikarigpioconfig->pwm_as_sck_off(); 
    }
    else if((basic_timer_cnt >= 11) && (basic_timer_cnt <= 15)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_3);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 16) && (basic_timer_cnt <= 20)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_4);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 21) && (basic_timer_cnt <= 25)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_5);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 26) && (basic_timer_cnt <= 30)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_6);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 31) && (basic_timer_cnt <= 35)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_7);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 36) && (basic_timer_cnt <= 40)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_8);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 41) && (basic_timer_cnt <= 45)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_9);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 46) && (basic_timer_cnt <= 50)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_10);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 51) && (basic_timer_cnt <= 55)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_11);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 56) && (basic_timer_cnt <= 60)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_12);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 61) && (basic_timer_cnt <= 65)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_13);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 66) && (basic_timer_cnt <= 70)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_14);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 71) && (basic_timer_cnt <= 65)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_15);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 76) && (basic_timer_cnt <= 80)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_16);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 81) && (basic_timer_cnt <= 85)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_17);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 86) && (basic_timer_cnt <= 90)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_18);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 91) && (basic_timer_cnt <= 95)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_19);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 96) && (basic_timer_cnt <= 100)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_20);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 101) && (basic_timer_cnt <= 105)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_21);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 106) && (basic_timer_cnt <= 110)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_22);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 111) && (basic_timer_cnt <= 115)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_23);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 116) && (basic_timer_cnt <= 120)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_24);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 121) && (basic_timer_cnt <= 125)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_25);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 126) && (basic_timer_cnt <= 130)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_26);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 131) && (basic_timer_cnt <= 135)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_27);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 131) && (basic_timer_cnt <= 135)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_28);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 136) && (basic_timer_cnt <= 140)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_29);
	    hikarigpioconfig->pwm_as_sck_off();
    }
    else if((basic_timer_cnt >= 141) && (basic_timer_cnt <= 145)){
        hikarigpioconfig->pwm_as_sck_on();
        test(test_30);
	    hikarigpioconfig->pwm_as_sck_off();
    }
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
            // fsm_state_clear();
            break;
        // case FSM_STATE_POWER_OFF:
        //     /* code */
            
        //     break;
        default:
            break;
    }
}