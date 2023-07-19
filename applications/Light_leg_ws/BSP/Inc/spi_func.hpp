#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include "para_def.h"

#define SPI1_NODE DT_NODELABEL(spi1)

const struct device *const spi1 = DEVICE_DT_GET(SPI1_NODE);

class HikariSPIConfig {
    public:
        static HikariSPIConfig *GetInstance() { return &_sInstance;}
        uint8_t my_spi_init(const struct device *dev);
        uint8_t my_spi_write(const struct device *dev, uint8_t tx_buffer[], size_t len);
        uint8_t my_spi_receive();
    private:
        static HikariSPIConfig _sInstance;
};
