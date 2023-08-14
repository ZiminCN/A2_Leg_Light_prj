/*
 * Copyright (c) 2021 Seagate Technology LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __WS2811_SPI_BINDINGS_H
#define __WS2811_SPI_BINDINGS_H

/*
 * At 4 MHz, 1 bit is 250 ns, so 3 bits is 750 ns.
 *
 * That's cutting it a bit close to the edge of the timing parameters,
 * but it seems to work on AdaFruit LED rings.
 */
#define SPI_FREQ    4000000
#define ZERO_FRAME  0x40
#define ONE_FRAME   0x70

#endif