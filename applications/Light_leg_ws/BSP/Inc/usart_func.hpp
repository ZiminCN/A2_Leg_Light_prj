#ifndef __USART_FUNC_HPP
#define __USART_FUNC_HPP

#include "string.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>
#include "para_def.h"

#define UART_NODE1 DT_NODELABEL(usart1)

const struct device *const uart1_node = DEVICE_DT_GET(UART_NODE1);

class HikariUARTConfig {
    public:
        static HikariUARTConfig *GetInstance() { return &_sInstance;}
        uint8_t fake_uart_write_byte(const struct device *dev, uint8_t t_byte);
        uint8_t fake_uart_init(const struct device *dev);
        uint8_t fake_uart_tx(const struct device *dev, uint8_t *tx_buffer, uint8_t tx_buffer_len);
        uint8_t fake_uart_receive_byte(const struct device *dev, uint8_t *t_byte);
        uint8_t fake_uart_rx(const struct device *dev, uint8_t *rx_buffer, uint8_t rx_buffer_len);
    private:
        static HikariUARTConfig _sInstance;
};


#endif //__USART_FUNC_HPP