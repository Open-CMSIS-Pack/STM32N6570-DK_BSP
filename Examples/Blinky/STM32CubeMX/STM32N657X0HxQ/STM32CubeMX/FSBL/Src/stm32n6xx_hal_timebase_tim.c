/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32n6xx_hal_timebase_tim.c
  * @brief   HAL time base based on the hardware TIM.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "stm32n6xx_hal.h"
#include "stm32n6xx_hal_tim.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef        htim18;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  This function configures the TIM18 as a time base source.
  *         The time source is configured  to have 1ms time base with a dedicated
  *         Tick interrupt priority.
  * @note   This function is called  automatically at the beginning of program after
  *         reset by HAL_Init() or at any time when clock is configured, by HAL_RCC_ClockConfig().
  * @param  TickPriority: Tick interrupt priority.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  RCC_ClkInitTypeDef    clkconfig;
  uint32_t              uwTimclock;
  uint32_t              uwPrescalerValue;

  /*Configure the TIM18 IRQ priority */
  HAL_NVIC_SetPriority(TIM18_IRQn, TickPriority ,0);
  /* Enable the TIM18 global Interrupt */
  HAL_NVIC_EnableIRQ(TIM18_IRQn);

  /* Enable TIM18 clock */
  __HAL_RCC_TIM18_CLK_ENABLE();

  /* Compute TIM18 clock */
  uwTimclock = HAL_RCCEx_GetTIMGFreq();

  /* Get clock configuration */
  HAL_RCC_GetClockConfig(&clkconfig);

  /* Compute the prescaler value to have TIM18 counter clock equal to 1MHz */
  uwPrescalerValue = (uint32_t) ((uwTimclock / 1000000U) - 1U);

  /* Initialize TIM18 */
  htim18.Instance = TIM18;

  /* Initialize TIMx peripheral as follow:
   * Period = [(TIM18CLK/1000) - 1]. to have a (1/1000) s time base.
   * Prescaler = (uwTimclock/1000000 - 1) to have a 1MHz counter clock.
   * ClockDivision = 0
   * Counter direction = Up
   */
  htim18.Init.Period = (1000000U / 1000U) - 1U;
  htim18.Init.Prescaler = uwPrescalerValue;
  htim18.Init.ClockDivision = 0;
  htim18.Init.CounterMode = TIM_COUNTERMODE_UP;

  if(HAL_TIM_Base_Init(&htim18) == HAL_OK)
  {
    /* Start the TIM time Base generation in interrupt mode */
    return HAL_TIM_Base_Start_IT(&htim18);
  }

  /* Return function status */
  return HAL_ERROR;
}

/**
  * @brief  Suspend Tick increment.
  * @note   Disable the tick increment by disabling TIM18 update interrupt.
  * @param  None
  * @retval None
  */
void HAL_SuspendTick(void)
{
  /* Disable TIM18 update Interrupt */
  __HAL_TIM_DISABLE_IT(&htim18, TIM_IT_UPDATE);
}

/**
  * @brief  Resume Tick increment.
  * @note   Enable the tick increment by Enabling TIM18 update interrupt.
  * @param  None
  * @retval None
  */
void HAL_ResumeTick(void)
{
  /* Enable TIM18 Update interrupt */
  __HAL_TIM_ENABLE_IT(&htim18, TIM_IT_UPDATE);
}

