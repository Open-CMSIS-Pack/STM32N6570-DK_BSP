/*---------------------------------------------------------------------------
 * Copyright (c) 2026 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#ifndef STM32N6570_DK_H_
#define STM32N6570_DK_H_

#include "GPIO_STM32.h"
#include "Driver_USART.h"
#include "Driver_USBD.h"
#include "cmsis_vstream.h"

// CMSIS Driver instances of Board peripherals
#define CMSIS_DRIVER_USBD   0           // Driver_USBD0

// CMSIS Driver instance for STDIO retarget
#define RETARGET_STDIO_UART 1

// CMSIS Drivers
extern ARM_DRIVER_USART     ARM_Driver_USART_(RETARGET_STDIO_UART);     // ST-LINK
extern ARM_DRIVER_USBD      ARM_Driver_USBD_(CMSIS_DRIVER_USBD);        // USB Device
extern vStreamDriver_t      Driver_vStreamAudioIn;                      // vStream Audio In

#ifdef   CMSIS_shield_header
#include CMSIS_shield_header
#endif

#endif // STM32N6570_DK_H_
