# Board: STMicroelectronics [STM32N6570-DK](https://www.st.com/en/evaluation-tools/stm32n6570-dk.html)

## FSBL_XIP (First Stage Bootloader Execute in Place) Board Layer

Device: **STM32N657X0HxQ**

System Core Clock: **600 MHz**

This setup is configured using **STM32CubeMX**, an interactive tool provided by STMicroelectronics for device configuration.
Refer to ["Configure STM32 Devices with CubeMX"](https://open-cmsis-pack.github.io/cmsis-toolbox/CubeMX/) for additional information.

### System Configuration

| System resource       | Setting
|:----------------------|:--------------------------------------
| Heap                  | 64 kB (configured in the STM32CubeMX)
| Stack (MSP)           |  2 kB (configured in the STM32CubeMX)

### STDIO mapping

**STDIO** is routed to Virtual COM port on the ST-LINK (using **USART1** peripheral)

### CMSIS-Driver mapping

| CMSIS-Driver          | Peripheral            | Board connector/component                     | Connection
|:----------------------|:----------------------|:----------------------------------------------|:------------------------------
| Driver_USART1         | USART1                | ST-LINK connector (CN14)                      | STDIN, STDOUT, STDERR
| Driver_USBD0          | USB_OTG_HS            | USB_OTG_HS connector (CN18)                   | CMSIS_USB_Device
| Driver_vStreamAudioIn | MDF (DMA)             | On-board digital microphone (MIC)             | CMSIS_VSTREAM_AUDIO_IN
| CMSIS-Driver VIO      | GPIO                  | LEDs (LD2, LD1) and User1 button (B2)         | CMSIS_VIO

### CMSIS-Driver Virtual I/O mapping

| CMSIS-Driver VIO      | Board component
|:----------------------|:--------------------------------------
| vioBUTTON0            | Tamper button (B4)
| vioBUTTON1            | User1 button  (B2)
| vioLED0               | LED red       (LD2)
| vioLED1               | LED Green     (LD1)

## Steps to Create Reference Applications using FSBL_XIP Layer

> **Prerequisites**
>
>- **Required ST tools and Firmware Package**
>   - [STM32CubeProgrammer 2.21.0](https://www.st.com/en/development-tools/stm32cubeprog.html)
>     - STM32_SigningTool_CLI: Verify the environment variable `STM32_PRG_PATH` points to the folder that contains `STM32_SigningTool_CLI.exe`

FSBL_XIP Layer with connections can be used to create [Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/).

### Clone and open [FSBL_XIP Example](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_XIP)

- Build **ExtMemLoader** Target Set, when the flash algorithm is built the file ExtMemLoader.axf appears in the root folder and should then be copied into the Reference Applications project described below
- Build **FSBL_Appli** Target Set to get FSBL binaries
  - FSBL-trusted.bin and [flash](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_XIP#load-application-to-target) the FSBL
(required only once)
  - FSBL.hex and FSBL.axf appears in the root folder and should then be copied into the Reference Applications project described below

### [Create new solution](https://mdk-packs.github.io/vscode-cmsis-solution-docs/create_app.html) in VS Code based on [Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/) with FSBL_XIP Layer for STM32N6570-DK board

- Update *.csolution.yml
  - Ensure `target-set` with `set`,`debugger` and `memory` configuration settings

    ```yaml
          target-set:
            - set:
              images:
                - project-context: <project_name>.<build-type>
                  load: symbols
                - image: $OutDir()$/Appli-trusted.bin
                  load-offset: 0x70100000
                  load: image
              debugger:
                name: ST-Link@pyOCD
                clock: 4000000
                protocol: swd
          memory:
            - name: Ext-Flash
              access: rx
              start: 0x70100000
              size: 0x00100000
              algorithm: ExtMemLoader.axf
          device: STM32N657X0HxQ
          board: STM32N6570-DK:Rev.C
    ```

- Update *.cproject.yml
  - Ensure support for following output types

    ```yaml
      output:
        type:
          - bin
          - elf
          - hex
          - map
    ```

  - Add post-build command to generate binary with header

    ```yaml
      # Post-build command to generate binary with header
      executes:
        - execute: Generate_trusted_bin
          run: $ENV{STM32_PRG_PATH}/STM32_SigningTool_CLI.exe -bin $input$ -s -nk -of 0x80000000 -align -t fsbl -o $output$ -hv 2.3
          input:
            - $bin()$
          output:
            - $OutDir()$/Appli-trusted.bin
    ```

- Copy the following files from the previous root folder `FSBL_XIP Example` project into the current root folder `Reference_Applications` project

  - ExtMemLoader.axf
  - FSBL.hex
  - FSBL.axf

- Build project

- [Flash](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_XIP#load-application-to-target) the application

#### Debug in VSCode

- To debug application in
  - **FLASH MODE**
    - Set the boot mode configuration in **flash mode** (BOOT1 switch position to 1-2) and reset board
    > To flash an unprogrammed (virgin) STM32N6570-DK board, ensure that the board is in development mode (BOOT1 switch position to 1-3).
    - Open `.vscode\launch.json` file and modify configuration named "STLink@pyOCD (launch)"
      - Comment line

      ```jsonc
      // "preLaunchTask": "CMSIS Load",
      ```

      - add commands into initCommands

      ```json
      "initCommands": [
          "monitor reset halt",
          "symbol-file \"FSBL.axf\"",
          "load FSBL.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak JumpToApplication",
          "continue",
          "symbol-file \"out/<project-name>/STM32N657X0HxQ/<build-type>/<project-name>.axf\"",
          "tbreak main"
      ```

      - add commands into customResetCommands

      ```json
      "customResetCommands": [
          "monitor reset halt",
          "maintenance flush register-cache",
          "maintenance flush dcache",
          "symbol-file \"FSBL.axf\"",
          "load FSBL.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak JumpToApplication",
          "continue",
          "symbol-file \"out/<project-name>/STM32N657X0HxQ/<build-type>/<project-name>.axf\"",
          "tbreak main",
          "continue"
      ```

    - Save launch.json
    - Click **Load & Debug application** button and now program should wait in main function to start debug
    - With Continue (F5) button, application should run in flash mode

  - **DEVELOPMENT MODE**
    - Set the boot mode configuration in **development mode** (BOOT1 switch position to 1-3) and reset board
    - Open `.vscode\launch.json` file and modify configuration named "STLink@pyOCD (launch)"
      - Comment line

      ```jsonc
      // "preLaunchTask": "CMSIS Load",
      ```

      - add commands into initCommands

      ```json
      "initCommands": [
          "monitor reset halt",
          "symbol-file \"FSBL.axf\"",
          "load FSBL.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak JumpToApplication",
          "continue",
          "symbol-file \"out/<project-name>/STM32N657X0HxQ/<build-type>/<project-name>.axf\"",
          "tbreak main"
      ```

      - add commands into customResetCommands

      ```json
      "customResetCommands": [
          "monitor reset halt",
          "maintenance flush register-cache",
          "maintenance flush dcache",
          "symbol-file \"FSBL.axf\"",
          "load FSBL.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak JumpToApplication",
          "continue",
          "symbol-file \"out/<project-name>/STM32N657X0HxQ/<build-type>/<project-name>.axf\"",
          "tbreak main",
          "continue"
      ```

    - Save launch.json
    - Click **Load & Debug application** button and now program should wait in main function to start debug
    - With Continue (F5) button, application should run in development mode
