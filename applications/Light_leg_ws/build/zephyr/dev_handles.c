#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/rcc@40021000:
 * Supported:
 *    - /soc/pin-controller@40010800/gpio@40011800
 *    - /soc/pin-controller@40010800/gpio@40011400
 *    - /soc/pin-controller@40010800/gpio@40011000
 *    - /soc/pin-controller@40010800/gpio@40010c00
 *    - /soc/pin-controller@40010800/gpio@40010800
 *    - /soc/rcc@40021000/reset-controller
 *    - /soc/serial@40013800
 *    - /soc/can@40006400
 *    - /soc/timers@40000800/pwm
 *    - /soc/timers@40000400/pwm
 *    - /soc/timers@40000000/pwm
 *    - /soc/spi@40013000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_8[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, DEVICE_HANDLE_ENDS };

/* 2 : /soc/interrupt-controller@40010400:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_41[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 3 : /soc/pin-controller@40010800/gpio@40011800:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_65[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 4 : /soc/pin-controller@40010800/gpio@40011400:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_64[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /soc/pin-controller@40010800/gpio@40011000:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_63[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/pin-controller@40010800/gpio@40010c00:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_20[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/pin-controller@40010800/gpio@40010800:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 * Supported:
 *    - /soc/spi@40013000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_49[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 14, DEVICE_HANDLE_ENDS };

/* 8 : /soc/rcc@40021000/reset-controller:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 * Supported:
 *    - /soc/serial@40013800
 *    - /soc/timers@40000800/pwm
 *    - /soc/timers@40000400/pwm
 *    - /soc/timers@40000000/pwm
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_25[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 9, 11, 12, 13, DEVICE_HANDLE_ENDS };

/* 9 : /soc/serial@40013800:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 *    - /soc/rcc@40021000/reset-controller
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_47[] = { 1, 8, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 10 : /soc/can@40006400:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_37[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 11 : /soc/timers@40000800/pwm:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 *    - /soc/rcc@40021000/reset-controller
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_68[] = { 1, 8, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 12 : /soc/timers@40000400/pwm:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 *    - /soc/rcc@40021000/reset-controller
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_33[] = { 1, 8, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 13 : /soc/timers@40000000/pwm:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 *    - /soc/rcc@40021000/reset-controller
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_28[] = { 1, 8, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 14 : /soc/spi@40013000:
 * Direct Dependencies:
 *    - /soc/rcc@40021000
 *    - /soc/pin-controller@40010800/gpio@40010800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_51[] = { 1, 7, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
