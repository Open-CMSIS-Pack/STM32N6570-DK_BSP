#ifndef REGIONS_STM32N6570_DK_H
#define REGIONS_STM32N6570_DK_H


//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------
//------ With VS Code: Open Preview for Configuration Wizard -------------------

// <n> Auto-generated using information from packs
// <i> Device Family Pack (DFP):   Keil::STM32N6xx_DFP@1.1.0
// <i> Board Support Pack (BSP):   Keil::STM32N6570-DK_BSP@1.0.0

// <h> ROM Configuration
// =======================
// <h> __ROM0 (is rwx memory: FSBL_CODE_S from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x34180400
//   <i> Contains Startup and Vector Table
#define __ROM0_BASE 0x34180400
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x0003FC00
#define __ROM0_SIZE 0x0003FC00
// </h>

// <h> __ROM1 (unused)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region.
#define __ROM1_BASE 0x0
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region.
#define __ROM1_SIZE 0x0
// </h>

// <h> __ROM2 (unused)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region.
#define __ROM2_BASE 0x0
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region.
#define __ROM2_SIZE 0x0
// </h>

// <h> __ROM3 (unused)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region.
#define __ROM3_BASE 0x0
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region.
#define __ROM3_SIZE 0x0
// </h>

// </h>

// <h> RAM Configuration
// =======================
// <h> __RAM0 (is rwx memory: FSBL_DATA_S from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x341C0000
//   <i> Contains uninitialized RAM, Stack, and Heap
#define __RAM0_BASE 0x341C0000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00040000
#define __RAM0_SIZE 0x00040000
// </h>

// <h> __RAM1 (is rwx memory: AXISRAM1_NS from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x24064000
#define __RAM1_BASE 0x24064000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x0009C000
#define __RAM1_SIZE 0x0009C000
// </h>

// <h> __RAM2 (is rwx memory: CACHEAXI_NS+VENCRAM_NS from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x243C0000
#define __RAM2_BASE 0x243C0000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00060000
#define __RAM2_SIZE 0x00060000
// </h>

// <h> __RAM3 (is rwx memory: GFXMMU_SLV_NS from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x25000000
#define __RAM3_BASE 0x25000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x01000000
#define __RAM3_SIZE 0x01000000
// </h>

// </h>

// <n> Resources that are not allocated to linker regions
// <i> rwx RAM:  FSBL_CODE_NS from DFP:    BASE: 0x24180400  SIZE: 0x0003FC00
// <i> rwx RAM:  FSBL_DATA_NS from DFP:    BASE: 0x241C0000  SIZE: 0x00040000
// <i> rwx RAM:  FLEXRAM_NS from DFP:      BASE: 0x24000000  SIZE: 0x00064000
// <i> rwx RAM:  FLEXRAM_S from DFP:       BASE: 0x34000000  SIZE: 0x00064000
// <i> rwx RAM:  AXISRAM1_S from DFP:      BASE: 0x34064000  SIZE: 0x0009C000
// <i> rwx RAM:  AXISRAM3_NS from DFP:     BASE: 0x24200000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM3_S from DFP:      BASE: 0x34200000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM4_NS from DFP:     BASE: 0x24270000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM4_S from DFP:      BASE: 0x34270000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM5_NS from DFP:     BASE: 0x242E0000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM5_S from DFP:      BASE: 0x342E0000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM6_NS from DFP:     BASE: 0x24350000  SIZE: 0x00070000
// <i> rwx RAM:  AXISRAM6_S from DFP:      BASE: 0x34350000  SIZE: 0x00070000
// <i> rwx RAM:  CACHEAXI_S from DFP:      BASE: 0x343C0000  SIZE: 0x00040000
// <i> rwx RAM:  VENCRAM_S from DFP:       BASE: 0x34400000  SIZE: 0x00020000
// <i> rwx RAM:  GFXMMU_SLV_S from DFP:    BASE: 0x35000000  SIZE: 0x01000000
// <i> rwx RAM:  AHBSRAM1_NS from DFP:     BASE: 0x28000000  SIZE: 0x00004000
// <i> rwx RAM:  AHBSRAM1_S from DFP:      BASE: 0x38000000  SIZE: 0x00004000
// <i> rwx RAM:  AHBSRAM2_NS from DFP:     BASE: 0x28004000  SIZE: 0x00004000
// <i> rwx RAM:  AHBSRAM2_S from DFP:      BASE: 0x38004000  SIZE: 0x00004000
// <i> rwx RAM:  Backup_SRAM_NS from DFP:  BASE: 0x2C000000  SIZE: 0x00002000
// <i> rwx RAM:  Backup_SRAM_S from DFP:   BASE: 0x3C000000  SIZE: 0x00002000
// <i> rwx RAM:  ITCM_NS from DFP:         BASE: 0x00000000  SIZE: 0x00040000
// <i> rwx RAM:  ITCM_S from DFP:          BASE: 0x10000000  SIZE: 0x00040000
// <i> rwx RAM:  DTCM_NS from DFP:         BASE: 0x20000000  SIZE: 0x00040000
// <i> rwx RAM:  DTCM_S from DFP:          BASE: 0x30000000  SIZE: 0x00040000


#endif /* REGIONS_STM32N6570_DK_H */
