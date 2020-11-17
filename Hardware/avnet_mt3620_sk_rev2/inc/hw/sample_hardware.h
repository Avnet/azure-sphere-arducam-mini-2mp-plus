/* Copyright (c) Neo
   Licensed under the MIT License. */

// This file defines the mapping from the MT3620 Avnet MT3620 Starter Kit to the
// 'sample hardware' abstraction used by the samples at https://github.com/xiongyu0523/azure-sphere-arducam-mini-2mp-plus.
// Some peripherals are on-board on the RDB, while other peripherals must be attached externally if needed.
// See https://docs.microsoft.com/en-us/azure-sphere/app-development/manage-hardware-dependencies for more information on how to use hardware abstractions
// to enable apps to work across multiple hardware variants.

// This file is autogenerated from ../../sample_hardware.json.  Do not edit it directly.

#pragma once
#include "avnet_mt3620_sk_rev2.h"

// Connect CS to Click 1, Header 2, Pin 1
#define ARDUCAM_CS AVNET_MT3620_SK_GPIO0

// Connect to OLED Display connector Pin 4(SDA) and Pin3(SCL)
#define ARDUCAM_I2C AVNET_MT3620_SK_ISU2_I2C

// Connect to Click 1: Header 2: Pin4(SCK), Pin5(MOSI) and Pin6(MOSI)
#define ARDUCAM_SPI AVNET_MT3620_SK_ISU0_SPI

