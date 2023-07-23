#include "gpio_func.hpp"

uint8_t HikariGPIOConfig::board_led_init(){

    bool err = INIT_VALUE_0;

    if(!(err = gpio_is_ready_dt(&BOARD_LED_A))){
        printk(">>>GPIO A READY FAIL!<<< \r\n");
        return MY_FUNC_CRASH;
    }

    if(!(err = gpio_is_ready_dt(&BOARD_LED_B))){
        printk(">>>GPIO B READY FAIL!<<< \r\n");
        return MY_FUNC_CRASH;
    }
    
    if(!(err = gpio_is_ready_dt(&BOARD_LED_C))){
        printk(">>>GPIO C READY FAIL!<<< \r\n");
        return MY_FUNC_CRASH;
    }

    gpio_pin_configure_dt(&BOARD_LED_A, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&BOARD_LED_B, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&BOARD_LED_C, GPIO_OUTPUT_ACTIVE);
    printk("GPIO A&B&C READY!\r\n");
    return MY_FUNC_OK;
}

void HikariGPIOConfig::test_led(){

    gpio_pin_set_dt(&BOARD_LED_A, 1);
    gpio_pin_set_dt(&BOARD_LED_B, 1);
    gpio_pin_set_dt(&BOARD_LED_C, 1);
    k_msleep(1000);

    gpio_pin_set_dt(&BOARD_LED_A, 0);
    gpio_pin_set_dt(&BOARD_LED_B, 0);
    gpio_pin_set_dt(&BOARD_LED_C, 0);
    k_msleep(1000);
}

void HikariGPIOConfig::board_led_a_on(){
    gpio_pin_set_dt(&BOARD_LED_A, 1);
}

void HikariGPIOConfig::board_led_a_off(){
    gpio_pin_set_dt(&BOARD_LED_A, 0);
}

void HikariGPIOConfig::board_led_b_on(){
    gpio_pin_set_dt(&BOARD_LED_B, 1);
}

void HikariGPIOConfig::board_led_b_off(){
    gpio_pin_set_dt(&BOARD_LED_B, 0);
}

void HikariGPIOConfig::board_led_c_on(){
    gpio_pin_set_dt(&BOARD_LED_C, 1);
}

void HikariGPIOConfig::board_led_c_off(){
    gpio_pin_set_dt(&BOARD_LED_C, 0);
}

uint8_t HikariGPIOConfig::pwm_init(){
    
    bool err = INIT_VALUE_0;

    if(!(err = device_is_ready(PWM_AS_SCK.dev))){
        printk(">>>PWM_AS_SCK INIT READY FAIL!<<< \r\n");
        return MY_FUNC_CRASH;
    }

    // if(!(err = device_is_ready(PWM_AS_SDI.dev))){
    //     printk(">>>PWM_AS_SDI INIT READY FAIL!<<< \r\n");
    //     return MY_FUNC_CRASH;
    // }

    printk("***PWM INIT READY!*** \r\n");
    return MY_FUNC_OK;
}

void HikariGPIOConfig::pwm_as_sck_on(){

    // pwm_set_dt(&PWM_AS_SCK, PWM_USEC(28.5), PWM_USEC(14.25));
    pwm_set_dt(&PWM_AS_SCK, PWM_USEC(200), PWM_USEC(100));
    // pwm_set_dt(&PWM_AS_SCK, PWM_USEC(50), PWM_USEC(25));
}

void HikariGPIOConfig::pwm_as_sck_off(){

    pwm_set_dt(&PWM_AS_SCK, PWM_USEC(28.5), PWM_USEC(0));
}


void HikariGPIOConfig::pwm_as_sdi_on(){

    // pwm_set_dt(&PWM_AS_SDI, PWM_USEC(30), PWM_USEC(15));
    // pwm_set_dt(&PWM_AS_SDI, PWM_MSEC(2000), PWM_MSEC(1000));
}