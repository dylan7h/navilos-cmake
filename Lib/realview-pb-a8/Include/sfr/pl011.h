#ifndef __PL011__H__
#define __PL011__H__

#include "types.h"

#define UARTDR                          0x000
#define     DR_OE                       BIT(11)
#define     DR_BE                       BIT(10)
#define     DR_PE                       BIT(9)
#define     DR_FE                       BIT(8)
#define     DR_DATA                     FIELD(0xFF, 0)
#define UARTRSR_ECR                     0x004
#define     RSR_ECR_OE                  BIT(3)
#define     RSR_ECR_BE                  BIT(2)
#define     RSR_ECR_PE                  BIT(1)
#define     RSR_ECR_FE                  BIT(0)
#define UARTFR                          0x018
#define     FR_RI                       BIT(8)
#define     FR_TXFE                     BIT(7)
#define     FR_RXFE                     BIT(6)
#define     FR_TXFF                     BIT(5)
#define     FR_RXFF                     BIT(4)
#define     FR_BUSY                     BIT(3)
#define     FR_DCD                      BIT(2)
#define     FR_DSR                      BIT(1)
#define     FR_CTS                      BIT(0)
#define UARTILPR                        0x020
#define     ILPR_ILPDVSR                FIELD(0xFF, 0)
#define UARTIBRD                        0x024
#define     IBRD_DIVINT                 FIELD(0xFFFF, 0)
#define UARTFBRD                        0x028
#define     FBRD_DIVFRAC                FIELD(0x3F, 0)
#define UARTLCR_H                       0x02C
#define     LCR_H_SPS                   BIT(7)
#define     LCR_H_WLEN                  FIELD(0x3, 5)
#define     LCR_H_FEN                   BIT(4)
#define     LCR_H_STP2                  BIT(3)
#define     LCR_H_EPS                   BIT(2)
#define     LCR_H_PEN                   BIT(1)
#define     LCR_H_BRK                   BIT(0)
#define UARTCR                          0x030
#define     CR_CTSEn                    BIT(15)
#define     CR_RTSEn                    BIT(14)
#define     CR_Out2                     BIT(13)
#define     CR_Out1                     BIT(12)
#define     CR_RTS                      BIT(11)
#define     CR_DTR                      BIT(10)
#define     CR_RXE                      BIT(9)
#define     CR_TXE                      BIT(8)
#define     CR_LBE                      BIT(7)
#define     CR_SIRLP                    BIT(2)
#define     CR_SIREN                    BIT(1)
#define     CR_UARTEN                   BIT(0)
#define UARTIFLS                        0x034
#define     IFLS_RXIFLSEL               FIELD(0x7, 3)
#define     IFLS_TXIFLSEL               FIELD(0x7, 0)
#define UARTIMSC                        0x038
#define UARTRIS                         0x03C
#define UARTMIS                         0x040
#define UARTICR                         0x044
#define     OE_MASK                     BIT(10)
#define     BE_MASK                     BIT(9)
#define     PE_MASK                     BIT(8)
#define     FE_MASK                     BIT(7)
#define     RT_MASK                     BIT(6)
#define     TX_MASK                     BIT(5)
#define     RX_MASK                     BIT(4)
#define     DSRM_MASK                   BIT(3)
#define     DCDM_MASK                   BIT(2)
#define     CTSM_MASK                   BIT(1)
#define     RIM_MASK                    BIT(0)
#define UARTDMACR                       0x048
#define     DMACR_DMAONERR              BIT(2)
#define     DMACR_TXDMAE                BIT(1)
#define     DMACR_RXDMAE                BIT(0)
#define UARTPeriphID                    0xFE0
#define     PeriphID_PartNumber(X)      EXTRACT(X, 0, 0xFFF)
#define     PeriphID_Designer(X)        EXTRACT(X, 12, 0xFF)
#define     PeriphID_RevisionNumber(X)  EXTRACT(X, 20, 0xF)
#define     PeriphID_Configuration(X)   EXTRACT(X, 24, 0xFF)
#define UARTPCellID                     0xFF0
#define     PCellID_0                   EXTRACT(X, 0, 0xFF)     /* 0x0D */
#define     PCellID_1                   EXTRACT(X, 8, 0xFF)     /* 0xF0 */
#define     PCellID_2                   EXTRACT(X, 16, 0xFF)    /* 0x05 */
#define     PCellID_3                   EXTRACT(X, 24, 0xFF)    /* 0xB1 */

#endif  //!__PL011__H__
