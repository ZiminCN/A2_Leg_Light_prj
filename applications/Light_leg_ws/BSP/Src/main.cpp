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
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);
#define BASIC_TIME_COUNT_STACK_SIZE 128

int main(void)
{	

	LOG_INF("Start Leg Board");

	ws2811_test();

	return 0;
}