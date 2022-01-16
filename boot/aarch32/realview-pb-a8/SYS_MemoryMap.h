#ifndef __SYS_MEMORYMAP__H__
#define __SYS_MEMORYMAP__H__

/* 
    Northbridge	                                        0x00000000-0x0FFFFFFF       DMC	256MB (DDR mirror)
    Southbridge	                                        0x10000000-0x1001FFFF       APB	128KB
        System registers                                0x10000000-0x10000FFF	    APB	4KB
        System controller 0	                            0x10001000-0x10001FFF	    APB	4KB
        3-Wire Serial Bus Control	                    0x10002000-0x10002FFF	    APB	4KB
        MultiMedia Card Interface	                    0x10005000-0x10005FFF	    APB	4KB
        UART 0 Interface	                            0x10009000-0x10009FFF       APB	4KB
        UART 1 Interface	                            0x10009000-0x1000AFFF       APB	4KB
        UART 2 Interface	                            0x10009000-0x1000BFFF       APB	4KB
        UART 3 Interface	                            0x10009000-0x1000CFFF       APB	4KB
        Synchronous Serial Port Interface	            0x1000D000-0x1000DFFF       APB	4KB
        Smart Card Interface	                        0x1000E000-0x1000EFFF	    APB	4KB
        Watchdog 0 Interface	                        0x1000F000-0x1000FFFF	    APB	4KB
        Watchdog 1 Interface                            0x10010000-0x10010FFF       APB	4KB
        Timer modules 0 and 1 Interface                 0x10011000-0x10011FFF       APB	4KB
        (Timer 1 registers start at 0x10011020)
        Timer modules 2 and 3 Interface                 0x10012000-0x10012FFF       APB	4KB
        (Timer 3 registers start at 0x10011020)
        Real Time Clock Interface                       0x10017000-0x10017FFF       APB	4KB
        Timer Modules 4 and 5 Interface                 0x10018000-0x10018FFF       APB	4KB
        (Timer 5 registers start at 0x10018020)	
        Timer Modules 6 and 7 Interface                 0x10019000-0x10019FFF	    APB	4KB
        (Timer 7 registers start at 0x10019020)	
        System Controller 1	                            0x1001A000-0x1001AFFF	    APB	4KB
        DMA Controller configuration                    0x10030000-0x1003FFFF	    AHB	64KB
        Internal Northbridge SRAM	                    0x10060000-0x1007FFFF	    AXI	128KB
        Dynamic Memory Controller configuration	        0x100E0000-0x100E0FFF       APB	4KB
        Static Memory Controller configuration	        0x100E1000-0x100E1FFF	    APB	4KB
        APB Registers (PLL configuration)	            0x100E3000-0x100E3FFF       APB	4KB
    Northbridge	                                        0x10020000-0x100DFFFF       AHB	768KB
    Northbridge	                                        0x100E0000-0x100FFFFF       APB	128KB
    Northbridge	                                        0x10100000-0x17FFFFFF       Reserved	127MB
    Southbridge	                                        0x18000000-0x1FFFFFFF       AHB	128MB
        Compact Flash	                                0x18000000-0x18000FFF       AHB	4KB
        DAP ROM table	                                0x1C000000-0x1DFFFFFF       AHB	32MB
        GIC1 (nIRQ interrupt handling for Cortex-A8)    0x1E000000-0x1E00FFFF       APB	64KB
        GIC2 (nFIQ interrupt handling for Cortex-A8)    0x1E010000-0x1E01FFFF       APB	64KB
        GIC3 (nIRQ interrupt handling for Tile Site)    0x1E020000-0x1E02FFFF       APB	64KB
        GIC4 (nFIQ interrupt handling for Tile Site)    0x1E030000-0x1E03FFFF       APB	64KB
    Northbridge	                                        0x20000000-0x3FFFFFFF       Reserved	512MB
    Northbridge	                                        0x40000000-0x5FFFFFFF       SMC	512MB
    Northbridge	                                        0x60000000-0x6FFFFFFF       PCI	256MB
    Northbridge	                                        0x70000000-0x8FFFFFFF       DMC	512MB
        Dynamic memory (CS0)	                        0x70000000-0x7FFFFFFF       DDR	256MB
        Dynamic memory (CS1)	                        0x80000000-0x8FFFFFFF       DDR	256MB
    Northbridge	                                        0x90000000-0xBFFFFFFF       PCI	768MB
    Logic Tile site	                                    0xC0000000-0xFFFFFFFF       External	1GB
 */

#endif  //!__SYS_MEMORYMAP__H__
