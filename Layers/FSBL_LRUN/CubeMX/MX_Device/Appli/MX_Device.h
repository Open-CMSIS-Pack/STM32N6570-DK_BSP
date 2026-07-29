/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 28/07/2026 09:37:10
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated with a generator out of the
 *               STM32CubeMX project and its generated files (DO NOT EDIT!)
 ******************************************************************************/

#ifndef MX_DEVICE_H__
#define MX_DEVICE_H__

/* MX_Device.h version */
#define MX_DEVICE_VERSION                       0x01000000


/*------------------------------ ETH1           -----------------------------*/
#define MX_ETH1                                 1

/* Pins */

/* ETH1_CLK */
#define MX_ETH1_CLK_Pin                         PF5
#define MX_ETH1_CLK_GPIO_Pin                    GPIO_PIN_5
#define MX_ETH1_CLK_GPIOx                       GPIOF
#define MX_ETH1_CLK_GPIO_Mode                   GPIO_MODE_AF_PP
#define MX_ETH1_CLK_GPIO_PuPd                   GPIO_PULLUP
#define MX_ETH1_CLK_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_CLK_GPIO_AF                     GPIO_AF11_ETH1

/* ETH1_MDC */
#define MX_ETH1_MDC_Pin                         PD1
#define MX_ETH1_MDC_GPIO_Pin                    GPIO_PIN_1
#define MX_ETH1_MDC_GPIOx                       GPIOD
#define MX_ETH1_MDC_GPIO_Mode                   GPIO_MODE_AF_PP
#define MX_ETH1_MDC_GPIO_PuPd                   GPIO_NOPULL
#define MX_ETH1_MDC_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_MDC_GPIO_AF                     GPIO_AF11_ETH1

/* ETH1_MDIO */
#define MX_ETH1_MDIO_Pin                        PD12
#define MX_ETH1_MDIO_GPIO_Pin                   GPIO_PIN_12
#define MX_ETH1_MDIO_GPIOx                      GPIOD
#define MX_ETH1_MDIO_GPIO_Mode                  GPIO_MODE_AF_PP
#define MX_ETH1_MDIO_GPIO_PuPd                  GPIO_NOPULL
#define MX_ETH1_MDIO_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_MDIO_GPIO_AF                    GPIO_AF11_ETH1

/* ETH1_PHY_INTN */
#define MX_ETH1_PHY_INTN_Pin                    PD3
#define MX_ETH1_PHY_INTN_GPIO_Pin               GPIO_PIN_3
#define MX_ETH1_PHY_INTN_GPIOx                  GPIOD
#define MX_ETH1_PHY_INTN_GPIO_Mode              GPIO_MODE_AF_PP
#define MX_ETH1_PHY_INTN_GPIO_PuPd              GPIO_NOPULL
#define MX_ETH1_PHY_INTN_GPIO_Speed             GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_PHY_INTN_GPIO_AF                GPIO_AF11_ETH1

/* ETH1_RGMII_CLK125 */
#define MX_ETH1_RGMII_CLK125_Pin                PF2
#define MX_ETH1_RGMII_CLK125_GPIO_Pin           GPIO_PIN_2
#define MX_ETH1_RGMII_CLK125_GPIOx              GPIOF
#define MX_ETH1_RGMII_CLK125_GPIO_Mode          GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_CLK125_GPIO_PuPd          GPIO_PULLUP
#define MX_ETH1_RGMII_CLK125_GPIO_Speed         GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_CLK125_GPIO_AF            GPIO_AF11_ETH1

/* ETH1_RGMII_GTX_CLK */
#define MX_ETH1_RGMII_GTX_CLK_Pin               PF0
#define MX_ETH1_RGMII_GTX_CLK_GPIO_Pin          GPIO_PIN_0
#define MX_ETH1_RGMII_GTX_CLK_GPIOx             GPIOF
#define MX_ETH1_RGMII_GTX_CLK_GPIO_Mode         GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_GTX_CLK_GPIO_PuPd         GPIO_PULLUP
#define MX_ETH1_RGMII_GTX_CLK_GPIO_Speed        GPIO_SPEED_FREQ_MEDIUM
#define MX_ETH1_RGMII_GTX_CLK_GPIO_AF           GPIO_AF12_ETH1

/* ETH1_RGMII_RXD0 */
#define MX_ETH1_RGMII_RXD0_Pin                  PF14
#define MX_ETH1_RGMII_RXD0_GPIO_Pin             GPIO_PIN_14
#define MX_ETH1_RGMII_RXD0_GPIOx                GPIOF
#define MX_ETH1_RGMII_RXD0_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_RXD0_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_RXD0_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_RXD0_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_RXD1 */
#define MX_ETH1_RGMII_RXD1_Pin                  PF15
#define MX_ETH1_RGMII_RXD1_GPIO_Pin             GPIO_PIN_15
#define MX_ETH1_RGMII_RXD1_GPIOx                GPIOF
#define MX_ETH1_RGMII_RXD1_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_RXD1_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_RXD1_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_RXD1_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_RXD2 */
#define MX_ETH1_RGMII_RXD2_Pin                  PF8
#define MX_ETH1_RGMII_RXD2_GPIO_Pin             GPIO_PIN_8
#define MX_ETH1_RGMII_RXD2_GPIOx                GPIOF
#define MX_ETH1_RGMII_RXD2_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_RXD2_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_RXD2_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_RXD2_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_RXD3 */
#define MX_ETH1_RGMII_RXD3_Pin                  PF9
#define MX_ETH1_RGMII_RXD3_GPIO_Pin             GPIO_PIN_9
#define MX_ETH1_RGMII_RXD3_GPIOx                GPIOF
#define MX_ETH1_RGMII_RXD3_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_RXD3_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_RXD3_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_RXD3_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_RX_CLK */
#define MX_ETH1_RGMII_RX_CLK_Pin                PF7
#define MX_ETH1_RGMII_RX_CLK_GPIO_Pin           GPIO_PIN_7
#define MX_ETH1_RGMII_RX_CLK_GPIOx              GPIOF
#define MX_ETH1_RGMII_RX_CLK_GPIO_Mode          GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_RX_CLK_GPIO_PuPd          GPIO_PULLUP
#define MX_ETH1_RGMII_RX_CLK_GPIO_Speed         GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_RX_CLK_GPIO_AF            GPIO_AF11_ETH1

/* ETH1_RGMII_RX_CTL */
#define MX_ETH1_RGMII_RX_CTL_Pin                PF10
#define MX_ETH1_RGMII_RX_CTL_GPIO_Pin           GPIO_PIN_10
#define MX_ETH1_RGMII_RX_CTL_GPIOx              GPIOF
#define MX_ETH1_RGMII_RX_CTL_GPIO_Mode          GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_RX_CTL_GPIO_PuPd          GPIO_PULLUP
#define MX_ETH1_RGMII_RX_CTL_GPIO_Speed         GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_RX_CTL_GPIO_AF            GPIO_AF11_ETH1

/* ETH1_RGMII_TXD0 */
#define MX_ETH1_RGMII_TXD0_Pin                  PF12
#define MX_ETH1_RGMII_TXD0_GPIO_Pin             GPIO_PIN_12
#define MX_ETH1_RGMII_TXD0_GPIOx                GPIOF
#define MX_ETH1_RGMII_TXD0_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_TXD0_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_TXD0_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_TXD0_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_TXD1 */
#define MX_ETH1_RGMII_TXD1_Pin                  PF13
#define MX_ETH1_RGMII_TXD1_GPIO_Pin             GPIO_PIN_13
#define MX_ETH1_RGMII_TXD1_GPIOx                GPIOF
#define MX_ETH1_RGMII_TXD1_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_TXD1_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_TXD1_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_TXD1_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_TXD2 */
#define MX_ETH1_RGMII_TXD2_Pin                  PG3
#define MX_ETH1_RGMII_TXD2_GPIO_Pin             GPIO_PIN_3
#define MX_ETH1_RGMII_TXD2_GPIOx                GPIOG
#define MX_ETH1_RGMII_TXD2_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_TXD2_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_TXD2_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_TXD2_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_TXD3 */
#define MX_ETH1_RGMII_TXD3_Pin                  PG4
#define MX_ETH1_RGMII_TXD3_GPIO_Pin             GPIO_PIN_4
#define MX_ETH1_RGMII_TXD3_GPIOx                GPIOG
#define MX_ETH1_RGMII_TXD3_GPIO_Mode            GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_TXD3_GPIO_PuPd            GPIO_PULLUP
#define MX_ETH1_RGMII_TXD3_GPIO_Speed           GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_TXD3_GPIO_AF              GPIO_AF11_ETH1

/* ETH1_RGMII_TX_CTL */
#define MX_ETH1_RGMII_TX_CTL_Pin                PF11
#define MX_ETH1_RGMII_TX_CTL_GPIO_Pin           GPIO_PIN_11
#define MX_ETH1_RGMII_TX_CTL_GPIOx              GPIOF
#define MX_ETH1_RGMII_TX_CTL_GPIO_Mode          GPIO_MODE_AF_PP
#define MX_ETH1_RGMII_TX_CTL_GPIO_PuPd          GPIO_PULLUP
#define MX_ETH1_RGMII_TX_CTL_GPIO_Speed         GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH1_RGMII_TX_CTL_GPIO_AF            GPIO_AF11_ETH1

/*------------------------------ I2C1           -----------------------------*/
#define MX_I2C1                                 1

/* Peripheral Clock Frequency */
#define MX_I2C1_PERIPH_CLOCK_FREQ               100000000


/*------------------------------ I2C2           -----------------------------*/
#define MX_I2C2                                 1

/* Peripheral Clock Frequency */
#define MX_I2C2_PERIPH_CLOCK_FREQ               100000000


/*------------------------------ USART1         -----------------------------*/
#define MX_USART1                               1

/* Virtual mode */
#define MX_USART1_VM                            VM_ASYNC
#define MX_USART1_VM_ASYNC                      1

/* Pins */

/* USART1_RX */
#define MX_USART1_RX_Pin                        PE6
#define MX_USART1_RX_GPIO_Pin                   GPIO_PIN_6
#define MX_USART1_RX_GPIOx                      GPIOE
#define MX_USART1_RX_GPIO_Mode                  GPIO_MODE_AF_PP
#define MX_USART1_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART1_RX_GPIO_Speed                 GPIO_SPEED_FREQ_LOW
#define MX_USART1_RX_GPIO_AF                    GPIO_AF7_USART1

/* USART1_TX */
#define MX_USART1_TX_Pin                        PE5
#define MX_USART1_TX_GPIO_Pin                   GPIO_PIN_5
#define MX_USART1_TX_GPIOx                      GPIOE
#define MX_USART1_TX_GPIO_Mode                  GPIO_MODE_AF_PP
#define MX_USART1_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART1_TX_GPIO_Speed                 GPIO_SPEED_FREQ_LOW
#define MX_USART1_TX_GPIO_AF                    GPIO_AF7_USART1

/*------------------------------ USB1_OTG_HS    -----------------------------*/
#define MX_USB1_OTG_HS                          1

/* Handle */
#define MX_USB1_OTG_HS_HANDLE                   hpcd_USB_OTG_HS1

/* Virtual mode */
#define MX_USB1_OTG_HS_VM                       Device_HS
#define MX_USB1_OTG_HS_Device_HS                1


#endif  /* MX_DEVICE_H__ */
