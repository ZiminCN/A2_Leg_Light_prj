# Copyright (c) Direct Drive Technology Co., Ltd. All rights reserved.
# Author: JianMing Zeng<JianMing.Zeng@directdrivetech.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
cmake_minimum_required(VERSION 3.20.0)

set(DTS_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../)
set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../)


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(A2_Light_Leg_cbt6_prj)

include_directories("${CMAKE_CURRENT_LIST_DIR}/BSP/Inc" 
                    "${CMAKE_CURRENT_LIST_DIR}/Core/SPI2Control/Inc" 
                    "${CMAKE_CURRENT_LIST_DIR}/Core/CAN2Control/Inc" 
                    "${CMAKE_CURRENT_LIST_DIR}/Core/UART2Control/Inc" 
                    "${CMAKE_CURRENT_LIST_DIR}/User/Inc")

file(GLOB APP_SOURCE BSP/Src/*.c BSP/Src/*.cpp 
                    Core/SPI2Control/Src/*.c Core/SPI2Control/Src/*.cpp
                    Core/UART2Control/Src/*.c Core/UART2Control/Src/*.cpp
                    Core/CAN2Control/Src/*.c Core/CAN2Control/Src/*.cpp
                    User/Src/*.c User/Src/*.cpp)

target_compile_definitions(app PRIVATE _GNU_SOURCE=1 DIABLO_Leg_ZEPHYR=1)

target_sources(app PRIVATE ${APP_SOURCE})