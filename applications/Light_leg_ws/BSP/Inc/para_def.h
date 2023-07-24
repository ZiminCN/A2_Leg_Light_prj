#ifndef __PARA_DEF_H
#define __PARA_DEF_H

#define THREAD_PRIORITY_AS_0 0
#define THREAD_PRIORITY_AS_1 1
#define THREAD_PRIORITY_AS_2 2
#define THREAD_PRIORITY_AS_3 3
#define THREAD_PRIORITY_AS_4 4
#define THREAD_PRIORITY_AS_5 5

#define MAX_PERIOD PWM_HZ(20000U)
#define MIN_PERIOD PWM_HZ(5000U)

//! The maximum timeout time significantly 
//! affects the response speed of the function
#ifndef I2C_MAX_TIMEOUT
#define I2C_MAX_TIMEOUT 1
#endif  //I2C_MAX_TIMEOUT

#ifndef UART_MAX_TIMEOUT
#define UART_MAX_TIMEOUT 1
#endif  //UART_MAX_TIMEOUT

#ifndef MY_FUNC_MAX_TIMEOUT
#define MY_FUNC_MAX_TIMEOUT
#endif //MY_FUN_MAX_TIMEOUT

#define FALSE (0U)
#define TRUE  (1U)

// #define SDI_ONE     (0x1E)
#define SDI_ONE     (0xFF)
#define SDI_ZERO    (0x00)

#define bit7_check  (0x80)
#define bit6_check  (0x40)
#define bit5_check  (0x20)
#define bit4_check  (0x10)
#define bit3_check  (0x8)
#define bit2_check  (0x4)
#define bit1_check  (0x2)
#define bit0_check  (0x1)

#define INIT_VALUE_0            (0x00)
#define INIT_VALUE_1            (0x01)

#define MY_FUNC_OK              (0x00U)
#define MY_FUNC_CRASH           (0x01U)

#define PROCESS_FLAG_LOOP_OFF   (0x00)
#define PROCESS_FLAG_LOOP_ON    (0x01)

#define INIT_RX_LEN_DEFAULT     (0x00U)
#define INIT_TX_LEN_DEFAULT     (0x01U)

typedef struct{
    /* data */
    uint8_t L_Value;    //Lightness Value
    uint8_t R_Value;    //Red Value
    uint8_t G_Value;    //Green Value
    uint8_t B_Value;    //Blue Value
}SDI_SINGLE_COLOR_STRUCT;

typedef SDI_SINGLE_COLOR_STRUCT SDI_INPUT_ARRAY[30];

typedef enum {
    FSM_STATE_POWER_ON    = 0x00U,
    FSM_STATE_POWER_OFF   = 0x01U,
    FSM_STATE_LOOP        = 0x02U
    // LIGHT_STATE_FLAG    = 0x00U,
}__attribute__((packed)) FSM_STATE;

#endif //__PARA_DEF_H