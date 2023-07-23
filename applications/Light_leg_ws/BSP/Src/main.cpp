// Copyright (c) Direct Drive Technology Co., Ltd. All rights reserved.
// Author: JianMing Zeng<JianMing.Zeng@directdrivetech.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "main.hpp"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

uint8_t spi_test_array[] = {

	1,0xFF,0xFF,0xFF,
	2,0,0xFF,0,
	3,0,0xFF,0,
	4,0xFF,0xFF,0xFF,
	5,0,0xFF,0,
	6,0,0xFF,0,
	7,0xFF,0xFF,0xFF,
	8,0,0xFF,0,
	9,0,0xFF,0,
	10,0xFF,0xFF,0xFF,
	11,0,0xFF,0,
	12,0,0xFF,0,
	13,0xFF,0xFF,0xFF,
	14,0,0xFF,0,
	15,0,0xFF,0,
	16,0xFF,0xFF,0xFF,
	17,0,0xFF,0,
	0,0,0xFF,0,
	0,0xFF,0xFF,0xFF,
	0,0,0xFF,0,
	0,0,0xFF,0,
	0,0xFF,0xFF,0xFF,
	0,0,0xFF,0,
	0,0,0xFF,0,
	0,0xFF,0xFF,0xFF,
	0,0,0xFF,0,
	0,0,0xFF,0,
	0,0xFF,0xFF,0xFF,
	0,0,0xFF,0,
	0,0,0xFF,0
	// 0, 0xFF, 0, 0,
	// 1, 0xFF, 0, 0,
	// 2, 0xFF, 0, 0,
	// 3, 0xFF, 0, 0,
	// 4, 0xFF, 0, 0,
	// 5, 0xFF, 0, 0,
	// 6, 0xFF, 0, 0,
	// 7, 0xFF, 0, 0,
	// 8, 0xFF, 0, 0,
	// 9, 0xFF, 0, 0,
	// 10, 0xFF, 0, 0,
	// 11, 0xFF, 0, 0,
	// 12, 0xFF, 0, 0,
	// 13, 0xFF, 0, 0,
	// 14, 0xFF, 0, 0,
	// 15, 0xFF, 0, 0,
	// 16, 0xFF, 0, 0,
	// 17, 0xFF, 0, 0,
	// 18, 0xFF, 0, 0,
	// 19, 0xFF, 0, 0,
	// 20, 0xFF, 0, 0,
	// 21, 0xFF, 0, 0,
	// 22, 0xFF, 0, 0,
	// 23, 0xFF, 0, 0,
	// 24, 0xFF, 0, 0,
	// 25, 0xFF, 0, 0,
	// 26, 0xFF, 0, 0,
	// 27, 0xFF, 0, 0,
	// 28, 0xFF, 0, 0,
	// 29, 0xFF, 0, 0
};

uint8_t clear_test_array[] = {
	0x00,0x00,0x00,0x00,
	0xE0,0x00,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,

	0xE0,0xFF,0xFF,0xFF,
	0xE0,0xFF,0xFF,0xFF,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,

	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,


	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0xE0,0xFF,0x00,0x00,
	0x00,0x00,0x00,0x00
};

uint8_t FFtest[] = {

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

SDI_COLOR_STRUCT array_test = {
	{0x00},{0x00},{0xFF}
};

int main(void)
{	
	HikariSPIControler *spi_def;
	HikariGPIOConfig *def;

	def->board_led_init();
	def->pwm_init();
	def->pwm_as_sck_on();
	k_usleep(1);
	// spi_def->rgb2spi_array_output_TEST(clear_test_array);
	spi_def->test(clear_test_array);
	// spi_def->new_test(FFtest);
	def->pwm_as_sck_off();

	while (1)
	{
	// 	/* code */
		// spi_def->rgb2spi_array_output_TEST(spi_test_array);
		// def->test_led();
	}
	return 0;
}