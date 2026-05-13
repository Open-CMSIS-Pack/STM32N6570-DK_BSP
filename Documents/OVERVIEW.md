# STM32N6570-DK_BSP

The **STMicroelectronics STM32N6570-DK Board Support Pack (BSP)**:

- Contains examples in *csolution format* for usage with the [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/) and the  [VS Code CMSIS Solution](https://marketplace.visualstudio.com/items?itemName=Arm.cmsis-csolution) extension.
- Requires the [Device Family Pack (DFP) for the STM32N6 series](https://www.keil.arm.com/packs/stm32n6xx_dfp-keil).
- Is configured with [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) for the Arm Compiler 6 (MDK).

## Content in *csolution format*

- [Examples/Blinky](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/Blinky) shows the basic usage of this board.
- [Examples/FSBL](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL) shows the FSBL usage of this board.
- [Examples/FSBL_LRUN](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_LRUN) shows the FSBL_LRUN usage of this board.
- [Examples/FSBL_XIP](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_XIP) shows the FSBL_XIP usage of this board.
- [Layers/FSBL](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL) for device-agnostic [Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/)that implements these API interfaces:

| Provided API Interface        | Description
|:------------------------------|:------------------------------------------------------------------------------
| CMSIS_USB_Device              | CMSIS-Driver USB Device connected to USB_OTG_HS connector (CN14)
| CMSIS_VIO                     | CMSIS-Driver VIO connected to LEDs (LD2, LD1) and USER button (B2)
| STDIN, STDOUT, STDERR         | Standard I/O connected to Virtual COM port on ST-LINK connector (CN14)
| CMSIS_VSTREAM_AUDIO_IN        | CMSIS-Driver vStream for on-board microphone MIC

- [Layers/FSBL_LRUN](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_LRUN) for device-agnostic [Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/)that implements these API interfaces:

| Provided API Interface        | Description
|:------------------------------|:------------------------------------------------------------------------------
| CMSIS_USB_Device              | CMSIS-Driver USB Device connected to USB_OTG_HS connector (CN14)
| CMSIS_VIO                     | CMSIS-Driver VIO connected to LEDs (LD2, LD1) and USER button (B2)
| STDIN, STDOUT, STDERR         | Standard I/O connected to Virtual COM port on ST-LINK connector (CN14)
| CMSIS_VSTREAM_AUDIO_IN        | CMSIS-Driver vStream for on-board microphone MIC

- [Layers/FSBL_XIP](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_XIP) for device-agnostic [Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/)that implements these API interfaces:

| Provided API Interface        | Description
|:------------------------------|:------------------------------------------------------------------------------
| CMSIS_USB_Device              | CMSIS-Driver USB Device connected to USB_OTG_HS connector (CN14)
| CMSIS_VIO                     | CMSIS-Driver VIO connected to LEDs (LD2, LD1) and USER button (B2)
| STDIN, STDOUT, STDERR         | Standard I/O connected to Virtual COM port on ST-LINK connector (CN14)
| CMSIS_VSTREAM_AUDIO_IN        | CMSIS-Driver vStream for on-board microphone MIC
