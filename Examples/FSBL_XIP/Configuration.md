
## Configuration in STM32CubeMX

### Select **Secure domain only** TrustZone feature

### Navigate to Project Manager

- Project tab: Ensure the **FSBL**, **Appli** and **ExtMemLoader** checkboxes are selected
- Code Generator tab: Check that **Copy only necessary library files** are selected

### Navigate to Pinout & Configuration

#### System core

- CORTEX_M55M_FSBL: Enable **CPU ICache** and **CPU DCache**
- GPIO: Select PO1 pin as **GPIO_output** and configure PO1 configuration:
  - Pin Context Assignment: **Application**
  - GPIO output level: Low
  - Add user label: `LD1_green`

#### Connectivity

- SDMMC2: Unselect **First Stage Boot Loader** checkbox to disable this peripheral (to avoid configuration issues)
- XSPI1: Unselect **First Stage Boot Loader** checkbox to disable this peripheral (to avoid configuration issues with PO1 `LD1_green`)
- XSPI2: Check that **First Stage Boot Loader** and **External Memory Loader** are selected under Runtime contexts and modify following parameter settings:
  - Fifo Threshold: **4**
  - Memory Type: **Macronix**
  - Memory size: **1GBits**

#### Middleware

- EXTMEM_MANAGER: Select **First Stage Boot Loader** under Runtime contexts and select **Activate External Memory Manager** checkbox and configure parameters:
  - Boot usecase:
    - Boot:
      - Select boot code generation: **Checked**
      - Selection of the boot system: **Execute In Place**
    - XIP:
      - select the source memory: **Memory 1**
      - Application offset: **0x00100000**
  - Memory 1:
    - Memory Instance: **XSPI2**
    - Number of memory data lines: **EXTMEM_LINK_CONFIG_8LINES**

- EXTMEM_LOADER: Select **Activate External Memory Loader** checkbox and configure following **External Memory Loader** parameters:
  - Number of sectors: **0x8000** (32768)
  - Sector size: **0x1000** Bytes (4096)

### Navigate to Clock Configuration

- Under **IC3 Clock Source** PLL section configure **IC3 Div** to **/24** to have **IC3 Clock** **50 MHz**

   ![STM32CubeMX IC3 CLOCK CONFIGURATION](ic3_clock_conf.png)
- Under **XSPI2 Source Mux** select IC3 to have **XSPI2 Clock** **50 MHz**

   ![STM32CubeMX XSPI2 SOURCE CONFIGURATION](xspi2_source_mux_conf.png)

### Click **GENERATE CODE**, if you get warnings click Yes to generate code

## Configuration in VSCode

### FSBL/FSBL.cproject.yml

- #### Add linker script

```yaml
  # Linker script definition
  linker:
    - script: ../STM32CubeMX/STM32N657X0HxQ/STM32CubeMX/MDK-ARM/FSBL/stm32n657xx_axisram2_fsbl.sct
      for-compiler: AC6
```

- #### Add post-build command to add header to the generated binary

```yaml
  # Post-build commands to add header
  executes:
    - execute: Generate_trusted_bin
      run: $ENV{STM32_PRG_PATH}/STM32_SigningTool_CLI.exe -bin $input$ -s -nk -of 0x80000000 -align -t fsbl -o $output$ -hv 2.3
      input:
        - $bin()$
      output:
        - $OutDir()$/FSBL-trusted.bin
```

> The OTP configuration for flash source selection is configurable via fuses in BOOTROM_CONFIG_2[8:5], OTP_WORD11 using **STM32CubeProgrammer**. Requires the **default** boot configuration to have sNOR device attached boot. For more information, please check [UM3234](https://www.st.com/resource/en/user_manual/um3234-how-to-proceed-with-boot-rom-on-stm32n6-mcus-stmicroelectronics.pdf).

### STM32CubeMX/STM32N657X0HxQ/FSBL.cgen.yml

- #### Comment redundant files

```yaml
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/core/memory_wrapper.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/core/systick_management.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/MDK-ARM/FlashDev.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/MDK-ARM/FlashPrg.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/STM32Cube/stm32_device_info.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/STM32Cube/stm32_loader_api.c
```

### Appli/Appli.cproject.yml

- #### Add linker script

```yaml
  # Linker script definition
  linker:
    - script: ../STM32CubeMX/STM32N657X0HxQ/STM32CubeMX/MDK-ARM/Appli/stm32n657xx_ROMxspi2.sct
      for-compiler: AC6
```

- #### Add post-build command to add header to the generated binary

```yaml
  # Post-build commands to add header
  executes:
    - execute: Generate_trusted_bin
      run: $ENV{STM32_PRG_PATH}/STM32_SigningTool_CLI.exe -bin $input$ -s -nk -of 0x80000000 -align -t fsbl -o $output$ -hv 2.3
      input:
        - $bin()$
      output:
        - $OutDir()$/Appli-trusted.bin
```

### STM32CubeMX/STM32N657X0HxQ/Appli.cgen.yml

- #### Comment following redundant files (temporarily issue with cmsis toolbox extension)

```yaml
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/core/memory_wrapper.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/core/systick_management.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/MDK-ARM/FlashDev.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/MDK-ARM/FlashPrg.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/STM32Cube/stm32_device_info.c
  # - file: ./STM32CubeMX/Middlewares/ST/STM32_ExtMem_Loader/STM32Cube/stm32_loader_api.c
```

### STM32CubeMX/STM32N657X0HxQ/STM32CubeMX/Appli/Src/main.c

- #### Add code to blink `LD1_green` LED

```c
    /* USER CODE BEGIN 3 */
    HAL_GPIO_TogglePin(LD1_green_GPIO_Port, LD1_green_Pin);
    HAL_Delay(500);
   }
    /* USER CODE END 3 */
```

### ExtMemLoader/ExtMemLoader.cproject.yml

- #### Modify TrustZone mode from secure to "off"

- #### Add linker script

```yaml
  # Linker script definition
  linker:
    - script: ../STM32CubeMX/STM32N657X0HxQ/STM32CubeMX/MDK-ARM/ExtMemLoader/stm32n6xx_extmemloader_mdkarm.sct
      for-compiler: AC6
```

- #### Add post build commands to move .axf to root

```yaml
  # Post-build commands
  executes:
    - execute: Copy_ExtMemLoader_to_root
      run: ${CMAKE_COMMAND} -E copy $input$ $output$
      input:
        - ../out/ExtMemLoader/STM32N657X0HxQ/Debug/ExtMemLoader.axf
      output:
        - ../ExtMemLoader.axf
```

### STM32CubeMX/STM32N657X0HxQ/ExtMemLoader.cgen.yml

- #### Comment redundant file

```yaml
  # - file: ./STM32CubeMX/MDK-ARM/startup_stm32n657xx_fsbl.c
```
