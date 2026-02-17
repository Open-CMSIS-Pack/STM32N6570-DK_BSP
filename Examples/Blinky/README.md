
# Blinky project

The **Blinky** project is a simple example that can be used to verify the
basic tool setup.

It is compliant to the Cortex Microcontroller Software Interface Standard (CMSIS)
and uses the CMSIS-RTOS2 API interface for RTOS functionality. The CMSIS-RTOS2 API
is available with various real-time operating systems, for example RTX5 or FreeRTOS.

## Operation

- At start
  - outputs "Blinky Example" to UART that is connected to ST-Link (baudrate 115200bps)
  - blinks vioLED0 in 1 sec interval.
- The vioBUTTON0 changes the blink frequency and start/stops vioLED1.

### CMSIS-Driver Virtual I/O mapping

| CMSIS-Driver VIO      | Board component
|:----------------------|:--------------------------------------
| vioBUTTON0            | Tamper button (B4)
| vioLED0               | LED Red       (LD2)
| vioLED1               | LED Green     (LD1)

## Steps to Build, Load and Debug using the Blinky csolution project

> **Prerequisites:**
>
>- **Required Packs:**
>   - [Keil.STM32N6xx_DFP 1.1.0](https://github.com/Open-CMSIS-Pack/STM32N6xx_DFP)
>   - [Keil.STM32N6570-DK_BSP](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP)
>- **Required CMSIS Tools and Extensions:**
>   - Arm CMSIS Solution 1.64.2
>   - Arm CMSIS Debugger 1.3.0
>- **Required ST tools and Firmware Package:**
>   - [STM32CubeMX 6.16.1](https://www.st.com/en/development-tools/stm32cubemx.html)
>     - [STM32Cube_FW_N6 1.3.0](https://www.st.com/en/embedded-software/stm32cuben6.html)
>   - [STM32CubeProgrammer 2.21.0](https://www.st.com/en/development-tools/stm32cubeprog.html)
>     - STM32_SigningTool_CLI: Verify the environment variable `STM32_PRG_PATH` points to the folder that contains `STM32_SigningTool_CLI.exe`

## Build and Load in VSCode

### In Activity bar under CMSIS click **Manage Solution Settings**

- Select **ExtMemLoader** Target Set and click **Build solution**
  - **ExtMemLoader** project should successfully build to have configured flash algorithm (check in root folder if ExtMemLoader.axf file appears)
- Continue with select **FSBL** Target Set
- Ensure **ST-Link@pyOCD** Debug Adapter is selected and **Update launch.json and tasks.json** checkbox is selected and click **Save** then click **Build solution**
  - FSBL project should successfully build into out folder
  - Set the boot mode configuration in **development mode** (BOOT1 switch position to 1-3) and reset board
  - To flash STM32N6570-DK board click **Views and More Actions** and click **Load application to target**
  - Set the boot mode configuration in **flash mode** (BOOT1 switch position to 1-2) and reset board
  - Configured `LD1_green` (GPIO PO.01) LED should blink (in FSBL/Src/main.c)

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
          "load out/FSBL/STM32N657X0HxQ/Debug/FSBL.hex",
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
          "load out/FSBL/STM32N657X0HxQ/Debug/FSBL.hex",
          "set $pc = Reset_Handler",
          "set $sp = (int) &Image$$ARM_LIB_STACK$$ZI$$Limit",
          "thbreak main",
          "continue"
      ```

    - Save launch.json
    - Click **Load & Debug application** button and now program should wait in main function to start debug
    - With Continue (F5) button, configured `LD1_green` (GPIO PO.01) LED should blink in development mode
