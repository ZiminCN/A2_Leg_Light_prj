#include "ws2811_drive.h"
#include <errno.h>
#include <string.h>

#define LOG_LEVEL 4
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(ws2812_drive);

#include <zephyr/kernel.h>
#include <zephyr/drivers/led_strip.h>
#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/util.h>

#define STRIP_NODE		DT_ALIAS(ledstrip)
#define STRIP_NUM_PIXELS	DT_PROP(DT_ALIAS(ledstrip), chain_length)

#define DELAY_TIME K_MSEC(1)

#define RGB(_r, _g, _b) { .r = (_r), .g = (_g), .b = (_b) }

static const struct led_rgb colors[] = {
	RGB(0xff, 0x00, 0x00), /* red */
	RGB(0x00, 0xff, 0x00), /* green */
	RGB(0x00, 0x00, 0xff), /* blue */

	RGB(0xff, 0xff, 0x00), /* blue */
	RGB(0xff, 0x00, 0xff), /* blue */
	RGB(0x00, 0xff, 0xff), /* blue */

	RGB(0x8f, 0xff, 0xff), /* blue */
};

struct led_rgb pixels[STRIP_NUM_PIXELS];

static const struct device *const strip = DEVICE_DT_GET(STRIP_NODE);

void ws2811_test()
{
	size_t cursor = 0, color = 0;
	int rc;

	if (device_is_ready(strip)) {
		LOG_INF("Found LED strip device %s", strip->name);
	} else {
		LOG_ERR("LED strip device %s is not ready", strip->name);
		return;
	}

	LOG_INF("Displaying pattern on strip");
	while (1) {
		// memset(&pixels, 0x00, sizeof(pixels));	//reset all pixels as zero
		memcpy(&pixels[cursor], &colors[color], sizeof(struct led_rgb));
		rc = led_strip_update_rgb(strip, pixels, STRIP_NUM_PIXELS);	// 1:   2:   3:rgb num

		if (rc) {
			LOG_ERR("couldn't update strip: %d", rc);
		}

		cursor++;
		if (cursor >= STRIP_NUM_PIXELS) {
			cursor = 0;
			color++;
			if (color == ARRAY_SIZE(colors)) {
				color = 0;
			}
		}

		k_sleep(DELAY_TIME);
	}
}