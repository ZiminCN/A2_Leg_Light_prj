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

int main(void)
{	
	// HikariSPIControler *hikarispicontroler;
	HikariGPIOConfig *def;

	def->board_led_init();
	while (1)
	{
		/* code */
		def->test_led();

	}
	
    // uint8_t test_array[] = {
    //     //seems is start frame

    // };
	// while (1)
	// {
	// 	/* code */
	// 	printk("**Now test SPI func!** \r\n");
	// 	hikarispicontroler->nomal_test_spi_write(test_array);
	// 	// k_msleep(50);
	// }
	

	return 0;
}