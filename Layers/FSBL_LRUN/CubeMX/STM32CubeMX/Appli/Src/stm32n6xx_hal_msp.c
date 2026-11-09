/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32n6xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  /* System interrupt init*/

  HAL_PWREx_EnableVddIO2();

  HAL_PWREx_EnableVddIO3();

  HAL_PWREx_EnableVddIO4();

  HAL_PWREx_EnableVddIO5();

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
  * @brief ETH MSP Initialization
  * This function configures the hardware resources used in this example
  * @param heth: ETH handle pointer
  * @retval None
  */
void HAL_ETH_MspInit(ETH_HandleTypeDef* heth)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(heth->Instance==ETH1)
  {
    /* USER CODE BEGIN ETH1_MspInit 0 */

    /* USER CODE END ETH1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ETH1;
    PeriphClkInitStruct.Eth1ClockSelection = RCC_ETH1CLKSOURCE_HCLK;

  /* USER CODE BEGIN MACADDRESS */

  /* USER CODE END MACADDRESS */

    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_ETH1_CLK_ENABLE();
    __HAL_RCC_ETH1MAC_CLK_ENABLE();
    __HAL_RCC_ETH1TX_CLK_ENABLE();
    __HAL_RCC_ETH1RX_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    /**ETH1 GPIO Configuration
    PD1     ------> ETH1_MDC
    PD12     ------> ETH1_MDIO
    PD3     ------> ETH1_PHY_INTN
    PF10     ------> ETH1_RGMII_RX_CTL
    PF7     ------> ETH1_RGMII_RX_CLK
    PF5     ------> ETH1_CLK
    PF15     ------> ETH1_RGMII_RXD1
    PF14     ------> ETH1_RGMII_RXD0
    PF8     ------> ETH1_RGMII_RXD2
    PF2     ------> ETH1_RGMII_CLK125
    PF9     ------> ETH1_RGMII_RXD3
    PG4     ------> ETH1_RGMII_TXD3
    PF11     ------> ETH1_RGMII_TX_CTL
    PG3     ------> ETH1_RGMII_TXD2
    PF13     ------> ETH1_RGMII_TXD1
    PF0     ------> ETH1_RGMII_GTX_CLK
    PF12     ------> ETH1_RGMII_TXD0
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_12|ETH_MDINT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH1;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_7|ETH_CLK_Pin|GPIO_PIN_15
                          |GPIO_PIN_14|ETH_RXD2_Pin|ETH_CLK125_Pin|ETH_RXD3_Pin
                          |GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH1;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ETH_TXD3_Pin|ETH_TX2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH1;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = ETH_GTX_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    GPIO_InitStruct.Alternate = GPIO_AF12_ETH1;
    HAL_GPIO_Init(ETH_GTX_CLK_GPIO_Port, &GPIO_InitStruct);

    /* ETH1 interrupt Init */
    HAL_NVIC_SetPriority(ETH1_IRQn, 8, 0);
    HAL_NVIC_EnableIRQ(ETH1_IRQn);
    /* USER CODE BEGIN ETH1_MspInit 1 */

    /* USER CODE END ETH1_MspInit 1 */

  }

}

/**
  * @brief ETH MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param heth: ETH handle pointer
  * @retval None
  */
void HAL_ETH_MspDeInit(ETH_HandleTypeDef* heth)
{
  if(heth->Instance==ETH1)
  {
    /* USER CODE BEGIN ETH1_MspDeInit 0 */

    /* USER CODE END ETH1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ETH1_CLK_DISABLE();
    __HAL_RCC_ETH1MAC_CLK_DISABLE();
    __HAL_RCC_ETH1TX_CLK_DISABLE();
    __HAL_RCC_ETH1RX_CLK_DISABLE();

    /**ETH1 GPIO Configuration
    PD1     ------> ETH1_MDC
    PD12     ------> ETH1_MDIO
    PD3     ------> ETH1_PHY_INTN
    PF10     ------> ETH1_RGMII_RX_CTL
    PF7     ------> ETH1_RGMII_RX_CLK
    PF5     ------> ETH1_CLK
    PF15     ------> ETH1_RGMII_RXD1
    PF14     ------> ETH1_RGMII_RXD0
    PF8     ------> ETH1_RGMII_RXD2
    PF2     ------> ETH1_RGMII_CLK125
    PF9     ------> ETH1_RGMII_RXD3
    PG4     ------> ETH1_RGMII_TXD3
    PF11     ------> ETH1_RGMII_TX_CTL
    PG3     ------> ETH1_RGMII_TXD2
    PF13     ------> ETH1_RGMII_TXD1
    PF0     ------> ETH1_RGMII_GTX_CLK
    PF12     ------> ETH1_RGMII_TXD0
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_1|GPIO_PIN_12|ETH_MDINT_Pin);

    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_10|GPIO_PIN_7|ETH_CLK_Pin|GPIO_PIN_15
                          |GPIO_PIN_14|ETH_RXD2_Pin|ETH_CLK125_Pin|ETH_RXD3_Pin
                          |GPIO_PIN_11|GPIO_PIN_13|ETH_GTX_CLK_Pin|GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOG, ETH_TXD3_Pin|ETH_TX2_Pin);

    /* ETH1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(ETH1_IRQn);
    /* USER CODE BEGIN ETH1_MspDeInit 1 */

    /* USER CODE END ETH1_MspDeInit 1 */
  }

}

/**
  * @brief UART MSP Initialization
  * This function configures the hardware resources used in this example
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(huart->Instance==USART1)
  {
    /* USER CODE BEGIN USART1_MspInit 0 */

    /* USER CODE END USART1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_CLKP;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PE5     ------> USART1_TX
    PE6     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = VCP_TX_Pin|VCP_RX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
    /* USER CODE BEGIN USART1_MspInit 1 */

    /* USER CODE END USART1_MspInit 1 */

  }

}

/**
  * @brief UART MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance==USART1)
  {
    /* USER CODE BEGIN USART1_MspDeInit 0 */

    /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PE5     ------> USART1_TX
    PE6     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOE, VCP_TX_Pin|VCP_RX_Pin);

    /* USART1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
    /* USER CODE BEGIN USART1_MspDeInit 1 */

    /* USER CODE END USART1_MspDeInit 1 */
  }

}

/**
  * @brief PCD MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hpcd: PCD handle pointer
  * @retval None
  */
void HAL_PCD_MspInit(PCD_HandleTypeDef* hpcd)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(hpcd->Instance==USB1_OTG_HS)
  {
    /* USER CODE BEGIN USB1_OTG_HS_MspInit 0 */

    /* USER CODE END USB1_OTG_HS_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USBOTGHS1;
    PeriphClkInitStruct.UsbPhy1ClockSelection = RCC_USBPHY1CLKSOURCE_HSE_DIV2;
    PeriphClkInitStruct.UsbOtgHs1ClockSelection = RCC_USBOTGHS1CLKSOURCE_HSE_DIRECT;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Enable VDDUSB */
    HAL_PWREx_EnableVddUSB();
    /* Peripheral clock enable */
    __HAL_RCC_USB1_OTG_HS_CLK_ENABLE();
    __HAL_RCC_USB1_OTG_HS_PHY_CLK_ENABLE();
    /* USB1_OTG_HS interrupt Init */
    HAL_NVIC_SetPriority(USB1_OTG_HS_IRQn, 8, 0);
    HAL_NVIC_EnableIRQ(USB1_OTG_HS_IRQn);
    /* USER CODE BEGIN USB1_OTG_HS_MspInit 1 */

    /*Resets the USB PHY and OTG HS to their default states*/
    LL_AHB5_GRP1_ForceReset(0x00800000);
    __HAL_RCC_USB1_OTG_HS_FORCE_RESET();
    __HAL_RCC_USB1_OTG_HS_PHY_FORCE_RESET();

    /*Select HSE clock divided by 2*/
    LL_RCC_HSE_SelectHSEDiv2AsDiv2Clock();

    /*Release Reset on USB PHY*/
    LL_AHB5_GRP1_ReleaseReset(0x00800000);

    /* Required few clock cycles before accessing USB PHY Controller Registers */
    __HAL_RCC_USB1_OTG_HS_CLK_ENABLE();
    HAL_Delay(1);

    USB1_HS_PHYC->USBPHYC_CR &= ~(0x7 << 0x4);
    USB1_HS_PHYC->USBPHYC_CR |= (0x1 << 16) | (0x2 << 4) | (0x1 << 2) | 0x1U;

    __HAL_RCC_USB1_OTG_HS_PHY_RELEASE_RESET();

    /* Required few clock cycles before Releasing Reset */
    HAL_Delay(1);

    __HAL_RCC_USB1_OTG_HS_RELEASE_RESET();
    __HAL_RCC_USB1_OTG_HS_PHY_CLK_ENABLE();

    /* USER CODE END USB1_OTG_HS_MspInit 1 */

  }

}

/**
  * @brief PCD MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hpcd: PCD handle pointer
  * @retval None
  */
void HAL_PCD_MspDeInit(PCD_HandleTypeDef* hpcd)
{
  if(hpcd->Instance==USB1_OTG_HS)
  {
    /* USER CODE BEGIN USB1_OTG_HS_MspDeInit 0 */

    /* USER CODE END USB1_OTG_HS_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USB1_OTG_HS_CLK_DISABLE();
    __HAL_RCC_USB1_OTG_HS_PHY_CLK_DISABLE();

    /* Disable VDDUSB */
      HAL_PWREx_DisableVddUSB();

    /* USB1_OTG_HS interrupt DeInit */
    HAL_NVIC_DisableIRQ(USB1_OTG_HS_IRQn);
    /* USER CODE BEGIN USB1_OTG_HS_MspDeInit 1 */

    /* USER CODE END USB1_OTG_HS_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
