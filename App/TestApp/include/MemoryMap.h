#ifndef __MEMORYMAP__H__
#define __MEMORYMAP__H__

/* 
    +++++++++++++++++++++   0x00000000 - 0x000FFFFF (1MB)
    +   text            +
    +++++++++++++++++++++   0x00100000 - 0x002FFFFF (2MB)
    +   USR/SYS Stack   + 
    +++++++++++++++++++++   0x00300000 - 0x003FFFFF (1MB)
    +   SVC Stack       +
    +++++++++++++++++++++   0x00400000 - 0x004FFFFF (1MB)
    +   IRQ Stack       +
    +++++++++++++++++++++   0x00500000 - 0x005FFFFF (1MB)
    +   FIQ Stack       +
    +++++++++++++++++++++   0x00600000 - 0x006FFFFF (1MB)
    +   ABT Stack       +
    +++++++++++++++++++++   0x00700000 - 0x007FFFFF (1MB)
    +   UND Stack       +
    +++++++++++++++++++++   0x00800000 - 0x047FFFFF (64MB)
    +   Task Stack      +
    +++++++++++++++++++++   0x04800000 - 0x048FFFFF (1MB)
    +   data/bss        +
    +++++++++++++++++++++   0x04900000 - 0x07FFFFFF (55MB)
    +   heap            +
    +++++++++++++++++++++
 */

#define INST_ADDR_START     0
#define USRSYS_ADDR_STRAT   0x00100000
#define SVC_ADDR_STRAT      0x00300000
#define IRQ_ADDR_STRAT      0x00400000
#define FIQ_ADDR_STRAT      0x00500000
#define ABT_ADDR_STRAT      0x00600000
#define UND_ADDR_STRAT      0x00700000
#define TASK_ADDR_STRAT     0x00800000
#define GLOBAL_ADDR_STRAT   0x04800000
#define DALLOC_ADDR_STRAT   0x04900000

#define INST_MEM_SIZE       (USRSYS_ADDR_STRAT - INST_ADDR_START)
#define USRSYS_STACK_SIZE   (SVC_ADDR_STRAT - USRSYS_ADDR_STRAT)
#define SVC_STACK_SIZE      (IRQ_ADDR_STRAT - SVC_ADDR_STRAT)
#define IRQ_STACK_SIZE      (FIQ_ADDR_STRAT - IRQ_ADDR_STRAT)
#define FIQ_STACK_SIZE      (ABT_ADDR_STRAT - FIQ_ADDR_STRAT)
#define ABT_STACK_SIZE      (UND_ADDR_STRAT - ABT_ADDR_STRAT)
#define UND_STACK_SIZE      (TASK_ADDR_STRAT - UND_ADDR_STRAT)
#define TASK_STACK_SIZE     (GLOBAL_ADDR_STRAT - TASK_ADDR_STRAT)
#define DALLOC_MEM_SIZE     (55 * 1024 * 1024)

#define USRSYS_STACK_TOP    (USRSYS_ADDR_STRAT + USRSYS_STACK_SIZE - 4)
#define SVC_STACK_TOP       (SVC_ADDR_STRAT + SVC_STACK_SIZE - 4)
#define IRQ_STACK_TOP       (IRQ_ADDR_STRAT + IRQ_STACK_SIZE - 4)
#define FIQ_STACK_TOP       (FIQ_ADDR_STRAT + FIQ_STACK_SIZE - 4)
#define ABT_STACK_TOP       (ABT_ADDR_STRAT + ABT_STACK_SIZE - 4)
#define UND_STACK_TOP       (UND_ADDR_STRAT + UND_STACK_SIZE - 4)
#define TASK_STACK_TOP      (TASK_ADDR_STRAT + TASK_STACK_SIZE - 4)

#endif  //!__MEMORYMAP__H__
