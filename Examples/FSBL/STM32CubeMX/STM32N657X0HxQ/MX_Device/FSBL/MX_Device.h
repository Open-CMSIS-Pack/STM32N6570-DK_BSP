/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 12/01/2026 10:19:01
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated with a generator out of the
 *               STM32CubeMX project and its generated files (DO NOT EDIT!)
 ******************************************************************************/

#ifndef MX_DEVICE_H__
#define MX_DEVICE_H__

/* MX_Device.h version */
#define MX_DEVICE_VERSION                       0x01000000


/*------------------------------ I2C1           -----------------------------*/
#define MX_I2C1                                 1

/* Filter Settings */
#define MX_I2C1_ANF_ENABLE                      1
#define MX_I2C1_DNF                             0

/* Peripheral Clock Frequency */
#define MX_I2C1_PERIPH_CLOCK_FREQ               200000000

/* Pins */

/* I2C1_SCL */
#define MX_I2C1_SCL_Pin                         PH9
#define MX_I2C1_SCL_GPIO_Pin                    GPIO_PIN_9
#define MX_I2C1_SCL_GPIOx                       GPIOH
#define MX_I2C1_SCL_GPIO_Mode                   GPIO_MODE_AF_OD
#define MX_I2C1_SCL_GPIO_PuPd                   GPIO_NOPULL
#define MX_I2C1_SCL_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_I2C1_SCL_GPIO_AF                     GPIO_AF4_I2C1

/* I2C1_SDA */
#define MX_I2C1_SDA_Pin                         PC1
#define MX_I2C1_SDA_GPIO_Pin                    GPIO_PIN_1
#define MX_I2C1_SDA_GPIOx                       GPIOC
#define MX_I2C1_SDA_GPIO_Mode                   GPIO_MODE_AF_OD
#define MX_I2C1_SDA_GPIO_PuPd                   GPIO_NOPULL
#define MX_I2C1_SDA_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_I2C1_SDA_GPIO_AF                     GPIO_AF4_I2C1

/*------------------------------ I2C2           -----------------------------*/
#define MX_I2C2                                 1

/* Filter Settings */
#define MX_I2C2_ANF_ENABLE                      1
#define MX_I2C2_DNF                             0

/* Peripheral Clock Frequency */
#define MX_I2C2_PERIPH_CLOCK_FREQ               200000000

/* Pins */

/* I2C2_SCL */
#define MX_I2C2_SCL_Pin                         PD14
#define MX_I2C2_SCL_GPIO_Pin                    GPIO_PIN_14
#define MX_I2C2_SCL_GPIOx                       GPIOD
#define MX_I2C2_SCL_GPIO_Mode                   GPIO_MODE_AF_OD
#define MX_I2C2_SCL_GPIO_PuPd                   GPIO_NOPULL
#define MX_I2C2_SCL_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_I2C2_SCL_GPIO_AF                     GPIO_AF4_I2C2

/* I2C2_SDA */
#define MX_I2C2_SDA_Pin                         PD4
#define MX_I2C2_SDA_GPIO_Pin                    GPIO_PIN_4
#define MX_I2C2_SDA_GPIOx                       GPIOD
#define MX_I2C2_SDA_GPIO_Mode                   GPIO_MODE_AF_OD
#define MX_I2C2_SDA_GPIO_PuPd                   GPIO_NOPULL
#define MX_I2C2_SDA_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_I2C2_SDA_GPIO_AF                     GPIO_AF4_I2C2

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
#define MX_USB1_OTG_HS_HANDLE                   hhcd_USB_OTG_HS2


/*------------------------------ USB2_OTG_HS    -----------------------------*/
#define MX_USB2_OTG_HS                          1

/* Handle */
#define MX_USB2_OTG_HS_HANDLE                   hhcd_USB_OTG_HS2

/* Virtual mode */
#define MX_USB2_OTG_HS_VM                       Host_HS
#define MX_USB2_OTG_HS_Host_HS                  1


#endif  /* MX_DEVICE_H__ */
