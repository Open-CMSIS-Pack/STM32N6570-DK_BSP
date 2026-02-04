[![Version](https://img.shields.io/github/v/release/Open-CMSIS-Pack/STM32N6570-DK_BSP?label=Release)](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/releases/latest)
[![License: Apache-2.0](https://img.shields.io/badge/License-Apache--2.0-green?label=License)](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/blob/main/LICENSE-Apache-2.0)
[![License: BSD-3-Clause](https://img.shields.io/badge/License-BSD--3--Clause-green?label=License)](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/blob/main/LICENSE-BSD-3-Clause)
[![Examples Build Test](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/STM32N6570-DK_BSP/Test-Examples.yml?logo=arm&logoColor=0091bd&label=Examples%20Build%20Test)](./.github/workflows/Test-Examples.yml)
[![Build pack](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/STM32N6570-DK_BSP/pack.yml?logo=arm&logoColor=0091bd&label=Build%20pack)](/.github/workflows/pack.yml)

# STM32N6570-DK_BSP

This is the development repository for the **STMicroelectronics STM32N6570-DK Board Support Pack (BSP)** - a CMSIS software pack that is designed to work with all compiler toolchains (Arm Compiler, GCC, IAR, LLVM). It is released as [CMSIS software pack](https://www.keil.arm.com/packs/stm32n6570-dk_bsp-keil) and therefore accessible by CMSIS-Pack enabled software development tools.

This BSP uses the generator integration of the [CMSIS-Toolbox to Configure STM32 Devices with CubeMX](https://open-cmsis-pack.github.io/cmsis-toolbox/CubeMX/) that is also supported in µVision 5.40 and higher.

## Repository top-level structure

Directory                   | Description
:---------------------------|:--------------
[.ci](./.ci)                | Files that are related to the Continuous Integration (CI) tests of this BSP.
[.github/workflows](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/.github/workflows)   | [GitHub Actions](#github-actions) scripts described below.
[CMSIS/Driver](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/CMSIS/Driver)             | Contains a [CMSIS-Driver VIO](https://arm-software.github.io/CMSIS_6/latest/Driver/group__vio__interface__gr.html) that is configured for the board peripherals.
[Documents](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Documents)                   | [Usage overview](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Documents/OVERVIEW.md) for examples and board documentation provided by STMicroelectronics.
[Examples/Blinky](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/Blinky)       | Blinky example in *csolution project format* using [CMSIS-Driver VIO](https://arm-software.github.io/CMSIS_6/latest/Driver/group__vio__interface__gr.html) and [CMSIS-Compiler](https://arm-software.github.io/CMSIS-Compiler/main/index.html) for printf I/O retargeting.
[Examples/FSBL](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL)           | FSBL example in *csolution project format* that provides the fsbl basic reference template.
[Examples/FSBL_LRUN](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_LRUN) | FSBL_LRUN example in *csolution project format* that provides the fsbl load and run reference template.
[Examples/FSBL_XIP](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Examples/FSBL_XIP)   | FSBL_XIP example in *csolution project format* that provides the fsbl execute-in-place reference template.
[Images](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/tree/main/Images)                         | [Pictures](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/blob/main/Images/stm32n6570-dk_large.png) of the board.

## Using the development repository

This development repository can be used in a local directory and [mapped as software pack](https://open-cmsis-pack.github.io/cmsis-toolbox/build-tools#install-a-repository) using for example `cpackget` with:

    cpackget add <path>/Keil.STM32N6570-DK_BSP.pdsc

## Generate software pack

The software pack is generated using bash shell scripts.

- `./gen_pack.sh` based on [Open-CMSIS-Pack/gen-pack](https://github.com/Open-CMSIS-Pack/gen-pack) generates the software pack.
Run this script locally with:

      STM32N6570-DK_BSP $ ./gen_pack.sh

## GitHub Actions

The repository uses GitHub Actions to generate the pack and build examples:

- `.github/workflows/pack.yml` based on [Open-CMSIS-Pack/gen-pack-action](https://github.com/Open-CMSIS-Pack/gen-pack-action) generates pack using the [Generate software pack](#generate-software-pack) scripts.
- `.github/workflows/Test-Examples.yml` test build of examples.

## Issues

Please feel free to raise an [issue on GitHub](https://github.com/Open-CMSIS-Pack/STM32N6570-DK_BSP/issues)
to report misbehavior (i.e. bugs) or start discussions about enhancements. This
is your best way to interact directly with the maintenance team and the community.
We encourage you to append implementation suggestions as this helps to decrease the
workload of the maintenance team.
