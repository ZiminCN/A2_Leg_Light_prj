#include "spi_func.hpp"

HikariSPIConfig HikariSPIConfig::_sInstance;

uint8_t HikariSPIConfig::my_spi_init(const struct device *dev){

    if (!device_is_ready(dev)) {
		printk(">>>SPI device %s is not ready<<<\n", dev->name);
		return MY_FUNC_CRASH;
	}else 
		printk("**SPI device %s is ready**\n", dev->name);

    return MY_FUNC_OK;
}

uint8_t HikariSPIConfig::my_spi_write(const struct device *dev, uint8_t tx_buffer[], size_t len){

    int err = INIT_VALUE_0;

    // if(my_spi_init(dev)){
    //     return MY_FUNC_CRASH;
    // }

    const struct spi_cs_control my_cs_gpio = {
        .gpio = GPIO_DT_SPEC_GET(SPI1_NODE, cs_gpios),
        .delay = 0U,
    };

    const struct spi_config spi1_cfg = {
        //!something incorrect at the frequency
        // .frequency = 400000,
        .frequency = 40000,
        .operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8) | \
                    SPI_MODE_CPOL | SPI_TRANSFER_MSB | \
                    SPI_CS_ACTIVE_HIGH,
        .slave = 1,
        .cs = &my_cs_gpio,
    };

    const struct spi_buf spi1_buf1 = {
        .buf = tx_buffer,
        .len = len,
    };

    const struct spi_buf_set spi1_buf_set1 = {
        .buffers = &spi1_buf1,
        .count = 1,
    };

    err = spi_write(dev, &spi1_cfg, &spi1_buf_set1);
    if(err){
        // printk("**SPI Write Error!**\r\n");
        return MY_FUNC_CRASH;
    }else 
        // printk("**SPI Write Right!**\r\n");
    
    return MY_FUNC_OK;
}

uint8_t HikariSPIConfig::my_spi_receive(){

    return MY_FUNC_OK;
}