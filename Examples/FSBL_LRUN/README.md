
# FSBL_LRUN Template for STM32N6570-DK_BSP board

The **FSBL_LRUN** project is a simple example that can be used to verify the
basic tool setup.

Project provides a reference FSBL LRUN template that can be used to build any firmware application to execute in internal RAM (sub-project Appli).
The ExtMemLoader subproject is a flash algorithm that generates a binary library capable of programming an application into external memory.

## Introduction

The bootROM copies FSBL image from external Flash (Octo SPI Flash Memory) into internal RAM (AXI SRAM2) and begins execution to initialize the caches and configure the clocks. Once this is complete, the application binary is copied from external flash into internal RAM (AXI SRAM2). After the copy operation finishes, the application begins execution.
Once the application runs, the `LD1_green` LED (GPIO PO.01) blink in an infinite loop with a 0.5 second period.

## Steps to Build, Load and Debug using the Basic Template csolution project

> **Prerequisites:**
>
>- **Required Packs:**
>   - [Keil.STM32N6xx_DFP](https://github.com/Open-CMSIS-Pack/STM32N6xx_DFP)
>   - [Keil.STM32N6570-DK_BSP](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP)
>- **Required CMSIS Tools and Extensions:**
>   - Arm CMSIS Solution 1.64.2
>   - Arm CMSIS Debugger 1.3.0
>- **Required ST tools and Firmware Package:**
>   - [STM32CubeMX 6.16.1](https://www.st.com/en/development-tools/stm32cubemx.html)
>     - [STM32Cube_FW_N6 1.3.0](https://www.st.com/en/embedded-software/stm32cuben6.html)
>   - [STM32CubeProgrammer 2.21.0](https://www.st.com/en/development-tools/stm32cubeprog.html)
>     - STM32_SigningTool_CLI: Verify the environment variable `STM32_PRG_PATH` points to the folder that contains `STM32_SigningTool_CLI.exe`

## Project Creation and Configuration

- Project is created and STM32N6570-DK board is selected in VSCode
- STM32N6570-DK Board is configured in [STM32CubeMX](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/blob/main/Examples/FSBL_LRUN/Configuration.md#in-stm32cubemx)
- STM32N6570-DK Board is configured in [VSCode](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/blob/main/Examples/FSBL_LRUN/Configuration.md#configuration-in-vscode)

## Build and Load in VSCode

### In Activity bar under CMSIS click **Manage Solution Settings**

- Select **ExtMemLoader** Target Set and click **Build solution**
  - **ExtMemLoader** project should successfully build to have configured flash algorithm (check in root folder if ExtMemLoader.axf file appears)
- Continue with select **FSBL_Appli** Target Set
- Ensure **ST-Link@pyOCD** Debug Adapter is selected and **Update launch.json and tasks.json** checkbox is selected and click **Save** then click **Build solution**
  - FSBL and Appli projects should successfully build into out folder
  - Set the boot mode configuration in **development mode** (BOOT1 switch position to 1-3) and reset board
  - To flash STM32N6570-DK board click **Views and More Actions** and click **Load application to target**
  - Set the boot mode configuration in **flash mode** (BOOT1 switch position to 1-2) and reset board
  - Configured `LD1_green` (GPIO PO.01) LED should blink (in Appli/Src/main.c)

## Debug in VSCode

- To debug application in:
  - **FLASH MODE:**
    - Set the boot mode configuration in **flash mode** (BOOT1 switch position to 1-2) and reset board
    > To flash an unprogrammed (virgin) STM32N6570-DK board, ensure that the board is in development mode (BOOT1 switch position to 1-3).
    - Open .vscode\launch.json file and modify configuration named "STLink@pyOCD (launch)" under **initCommands** and **customResetCommands** commands:
      - Modify the command name from **tbreak main** to **thbreak main**
    - Click **Load & Debug application** button and now program should wait in main function to start debug
    - With Continue (F5) button, `LD1_green` (GPIO PO.01) LED should blink in flash mode

  - **DEVELOPMENT MODE:**
    - Set the boot mode configuration in **development mode** (BOOT1 switch position to 1-3) and reset board
    - Open .vscode\launch.json file and modify configuration named "STLink@pyOCD (launch)"
      - Comment line

      ```jsonc
      // "preLaunchTask": "CMSIS Load",
      ```

      - add commands into initCommands

      ```json
      "initCommands": [
          "monitor reset halt",
          "load out/Appli/STM32N657X0HxQ/Debug/Appli.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak main"
      ```

      - add commands into customResetCommands

      ```json
      "customResetCommands": [
          "monitor reset halt",
          "maintenance flush register-cache",
          "maintenance flush dcache",
          "load out/Appli/STM32N657X0HxQ/Debug/Appli.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak main",
          "continue"
      ```

    - Save launch.json
    - Click **Load & Debug application** button and now program should wait in main function to start debug
    - With Continue (F5) button, configured `LD1_green` (GPIO PO.01) LED should blink in development mode
