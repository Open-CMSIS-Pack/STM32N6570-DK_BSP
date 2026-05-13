/******************************************************************************
 * @file     vstream_audio_in.h
 * @brief    CMSIS Virtual Streaming interface Driver header for
 *           Audio In (microphone) on the
 *           STMicroelectronics STM32N6570-DK board
 * @version  V1.0.0
 * @date     27. March 2026
 ******************************************************************************/
/*
 * Copyright (c) 2026 Arm Limited. All rights reserved.
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
 */

#ifndef VSTREAM_AUDIO_IN_H_
#define VSTREAM_AUDIO_IN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_vstream.h"

extern vStreamDriver_t Driver_vStreamAudioIn;

#ifdef __cplusplus
}
#endif

#endif /* VSTREAM_AUDIO_IN_H_ */
