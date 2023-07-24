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

#define BASIC_TIME_COUNT_STACK_SIZE 128

//timer
int basic_timer_cnt = INIT_VALUE_0;
void basic_timer_counter(struct k_timer *timer){
	
	basic_timer_cnt += 1;

	if(basic_timer_cnt > 100){
		basic_timer_cnt = 0;
	}
}
K_TIMER_DEFINE(basic_timer_counter_sys, basic_timer_counter, NULL);
//threads
// static struct k_thread basic_time_count_thread;
// K_THREAD_STACK_DEFINE(basic_time_count_area, BASIC_TIME_COUNT_STACK_SIZE);

FSM_STATE fsm_state;

int main(void)
{	
	HikariSPIControler *spi_def;
	HikariGPIOConfig *def;
	k_timer_start(&basic_timer_counter_sys, K_MSEC(20), K_MSEC(20));

	def->board_led_init();
	def->pwm_init();
	spi_def->my_spi_init(fsm_state);

	while (1)
	{
	// 	/* code */

		spi_def->update_light(fsm_state);
		// spi_def->rgb2spi_array_output_TEST(spi_test_array);
		// def->test_led();
	}
	return 0;
}