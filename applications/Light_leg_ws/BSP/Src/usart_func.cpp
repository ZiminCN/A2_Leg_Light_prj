#include "usart_func.hpp"

HikariUARTConfig HikariUARTConfig::_sInstance;


/* this is a sample uart configure */
const struct uart_config my_uart_cfg = {
    /* data */
    .baudrate = 460800,
    .parity = UART_CFG_PARITY_NONE,
    .stop_bits = UART_CFG_STOP_BITS_1,
    .data_bits = UART_CFG_DATA_BITS_8,
    .flow_ctrl = UART_CFG_FLOW_CTRL_NONE
};

/**
 * @brief  initialize the uart configure
 * Sets UART configuartion using data from *dev.
 * 
 * @param dev select device what you configed at the dts.
 * 
 * @retval MY_FUNC_OK       if func successed 
 * @retval MY_FUNC_CRASH    if func failed
*/
uint8_t HikariUARTConfig::fake_uart_init(const struct device *dev){

    uint8_t err = INIT_VALUE_1;

    while (err){
    
        err = uart_configure(dev, &my_uart_cfg);
    }
    
    return MY_FUNC_OK;
}

/**
 * @brief receive data from uart port, 
 * but this func is non-authoritative.
 *
 * @param dev select device what you configed at the dts.
 * @param t_byte a byte what uart receive
 * 
 * @retval MY_FUNC_OK       if func successed 
 * @retval MY_FUNC_CRASH    if func failed
*/
uint8_t HikariUARTConfig::fake_uart_receive_byte(const struct device *dev, uint8_t *t_byte){
    
    uint8_t err = INIT_VALUE_1;

    while (err){
        
        err = uart_poll_in(dev, t_byte);
    }

    return MY_FUNC_OK;
}

/**
 * @brief transmit data from uart port,
 * but this func is non-authoritative.
 * 
 * @param dev select device what you configed at the dts.
 * @param t_byte a byte what you want to transmit
 * 
 * @retval MY_FUNC_OK       if func successed 
*/
uint8_t HikariUARTConfig::fake_uart_write_byte(const struct device *dev, uint8_t t_byte){

    uart_poll_out(dev, t_byte);
        
    return MY_FUNC_OK;
}

/**
 * @brief receive data from uart port,
 * but this func is non-authoritative.
 * 
 * @param dev select device what you configed at the dts.
 * @param rx_buffer select device what you configed at the dts
 * 
 * @retval MY_FUNC_OK       if func successed 
 * @retval MY_FUNC_CRASH    if func failed
*/
uint8_t HikariUARTConfig::fake_uart_rx(const struct device *dev, uint8_t *rx_buffer,
                                        uint8_t rx_buffer_len){
    
    // uint8_t init_len = INIT_LEN_DEFAULT;
    uint8_t init_len = INIT_RX_LEN_DEFAULT;

    uint8_t *rx_buffer_ptr = rx_buffer;

    while (init_len < rx_buffer_len){
        
        fake_uart_receive_byte(dev, rx_buffer_ptr);
        rx_buffer_ptr++;
        init_len++;
    }
    return MY_FUNC_OK;
}

/**
 * @brief transmit data
 * 
 * @param dev const struct uart_config instance
 * @param t_byte a byte what you want to transmit
 * 
 * @retval MY_FUNC_OK       if func successed 
 * @retval MY_FUNC_CRASH    if func failed
*/
uint8_t HikariUARTConfig::fake_uart_tx(const struct device *dev, uint8_t *tx_buffer, 
                                        uint8_t tx_buffer_len){

    uint8_t init_len = INIT_TX_LEN_DEFAULT;
    uint8_t *tx_buffer_ptr = tx_buffer;

    while (init_len < tx_buffer_len){
        
        fake_uart_write_byte(dev, *tx_buffer_ptr);
        tx_buffer_ptr++;
        init_len++;
    }
    
    return MY_FUNC_OK;
}
