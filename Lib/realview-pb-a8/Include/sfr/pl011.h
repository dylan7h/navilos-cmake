#ifndef __PL011__H__
#define __PL011__H__

#include "types.h"

#define UARTDR                          0x000                   /* Data Register */
#define     DR_OE                       BIT(11)                 /* Overrun error. */
#define     DR_BE                       BIT(10)                 /* Break error. */
#define     DR_PE                       BIT(9)                  /* Parity error. */
#define     DR_FE                       BIT(8)                  /* Framing error. */
#define     DR_DATA                     FIELD(0xFF, 0)          /* Receive/Transmit data character. */
#define UARTRSR_ECR                     0x004                   /* Receive Status Register/Error Clear Register */
#define     RSR_ECR_OE                  BIT(3)                  /* This bit is cleared to 0 by a write to UARTECR. */
#define     RSR_ECR_BE                  BIT(2)                  /* This bit is cleared to 0 by a write to UARTECR. */
#define     RSR_ECR_PE                  BIT(1)                  /* This bit is cleared to 0 by a write to UARTECR. */
#define     RSR_ECR_FE                  BIT(0)                  /* This bit is cleared to 0 by a write to UARTECR. */
#define UARTFR                          0x018                   /* Flag Register */
#define     FR_RI                       BIT(8)                  /* Ring indicator. */
#define     FR_TXFE                     BIT(7)                  /* Transmit FIFO empty. */
#define     FR_RXFE                     BIT(6)                  /* Receive FIFO full. */
#define     FR_TXFF                     BIT(5)                  /* Transmit FIFO full. */
#define     FR_RXFF                     BIT(4)                  /* Receive FIFO empty. */
#define     FR_BUSY                     BIT(3)                  /* UART busy. */
#define     FR_DCD                      BIT(2)                  /* Data carrier detect. */
#define     FR_DSR                      BIT(1)                  /* Data set ready. */
#define     FR_CTS                      BIT(0)                  /* Clear to send. */
#define UARTILPR                        0x020                   /* IrDA Low-Power Counter Register */
#define     ILPR_ILPDVSR                FIELD(0xFF, 0)          /* 8-bit low-power divisor value */
#define UARTIBRD                        0x024                   /* Integer Baud Rate Register */
#define     IBRD_DIVINT                 FIELD(0xFFFF, 0)        /* The integer baud rate divisor. */
#define UARTFBRD                        0x028                   /* Fractional Baud Rate Register */
#define     FBRD_DIVFRAC                FIELD(0x3F, 0)          /* The fractional baud rate divisor. */
#define UARTLCR_H                       0x02C                   /* Line Control Register */
#define     LCR_H_SPS                   BIT(7)                  /* Stick parity select */
#define     LCR_H_WLEN                  FIELD(0x3, 5)           /* Word length */
#define         WLEN_8_BIT              FIELD(0x3, 5)
#define         WLEN_7_BIT              FIELD(0x2, 5)
#define         WLEN_6_BIT              FIELD(0x1, 5)
#define         WLEN_5_BIT              FIELD(0x0, 5)
#define     LCR_H_FEN                   BIT(4)                  /* Enable FIFOs */
#define     LCR_H_STP2                  BIT(3)                  /* Two stop bits select. */
#define     LCR_H_EPS                   BIT(2)                  /* Even parity select. */
#define     LCR_H_PEN                   BIT(1)                  /* Parity enable */
#define     LCR_H_BRK                   BIT(0)                  /* Send break. */
/* 
    [ Parity truth table ]
    PEN     EPS     SPS     Parity bit (transmitted or checked)
    0       x       x       Not transmitted or checked
    1       1       0       Even parity
    1       0       1       Odd parity
    1       0       1       1
    1       1       1       0
 */

#define UARTCR                          0x030                   /* Control Register */
#define     CR_CTSEn                    BIT(15)                 /* CTS hardware flow control enable. */
#define     CR_RTSEn                    BIT(14)                 /* RTS hardware flow control enable. */
#define     CR_Out2                     BIT(13)                 /* This bit is the complement of the UART Out2 (nUARTOut2) modem status output. */
#define     CR_Out1                     BIT(12)                 /* This bit is the complement of the UART Out1 (nUARTOut1) modem status output. */
#define     CR_RTS                      BIT(11)                 /* Request to send. */
#define     CR_DTR                      BIT(10)                 /* Data transmit ready. */
#define     CR_RXE                      BIT(9)                  /* Receive enable. */
#define     CR_TXE                      BIT(8)                  /* Transmit enable */
#define     CR_LBE                      BIT(7)                  /* Loopback enable */
#define     CR_SIRLP                    BIT(2)                  /* SIR low-power IrDA mode */
#define     CR_SIREN                    BIT(1)                  /* SIR enable */
#define     CR_UARTEN                   BIT(0)                  /* UART enable */
#define UARTIFLS                        0x034                   /* Interrupt FIFO Level Select Register */
#define     IFLS_RXIFLSEL               FIELD(0x7, 3)           /* Receive interrupt FIFO level select */
#define         RXIFL_1_8_FULL          FIELD(0x0, 3)           /* Receive FIFO becomes ≥ 1/8 full */
#define         RXIFL_1_4_FULL          FIELD(0x1, 3)           /* Receive FIFO becomes ≥ 1/4 full */
#define         RXIFL_1_2_FULL          FIELD(0x2, 3)           /* Receive FIFO becomes ≥ 1/2 full */
#define         RXIFL_3_4_FULL          FIELD(0x3, 3)           /* Receive FIFO becomes ≥ 3/4 full */
#define         RXIFL_7_8_FULL          FIELD(0x4, 3)           /* Receive FIFO becomes ≥ 7/8 full */
#define     IFLS_TXIFLSEL               FIELD(0x7, 0)           /* Transmit interrupt FIFO level select */
#define         TXIFL_1_8_FULL          FIELD(0x0, 0)           /* Transmit FIFO becomes ≤ 1/ full */
#define         TXIFL_1_4_FULL          FIELD(0x1, 0)           /* Transmit FIFO becomes ≤ 1/4 full */
#define         TXIFL_1_2_FULL          FIELD(0x2, 0)           /* Transmit FIFO becomes ≤ 1/2 full */
#define         TXIFL_3_4_FULL          FIELD(0x3, 0)           /* Transmit FIFO becomes ≤ 3/4 full */
#define         TXIFL_7_8_FULL          FIELD(0x4, 0)           /* Transmit FIFO becomes ≤ 7/8 full */
#define UARTIMSC                        0x038                   /* Interrupt Mask Set/Clear Register */
#define UARTRIS                         0x03C                   /* Raw Interrupt Status Register */
#define UARTMIS                         0x040                   /* Masked Interrupt Status Register */
#define UARTICR                         0x044                   /* Interrupt Clear Register */
#define     OE_MASK                     BIT(10)                 /* Overrun error interrupt mask/status/clear */
#define     BE_MASK                     BIT(9)                  /* Break error interrupt mask/status/clear */
#define     PE_MASK                     BIT(8)                  /* Parity error interrupt mask/status/clear */
#define     FE_MASK                     BIT(7)                  /* Framing error interrupt mask/status/clear */
#define     RT_MASK                     BIT(6)                  /* Receive timeout interrupt mask/status/clear */
#define     TX_MASK                     BIT(5)                  /* Transmit interrupt mask/status/clear */
#define     RX_MASK                     BIT(4)                  /* Receive interrupt mask/status/clear */
#define     DSRM_MASK                   BIT(3)                  /* nUARTDSR modem interrupt mask/status/clear */
#define     DCDM_MASK                   BIT(2)                  /* nUARTDCD modem interrupt mask/status/clear */
#define     CTSM_MASK                   BIT(1)                  /* nUARTCTS modem interrupt mask/status/clear */
#define     RIM_MASK                    BIT(0)                  /* nUARTRI modem interrupt mask/status/clear */
#define UARTDMACR                       0x048                   /* DMA Control Register */
#define     DMACR_DMAONERR              BIT(2)                  /* DMA on error */
#define     DMACR_TXDMAE                BIT(1)                  /* Transmit DMA enable */
#define     DMACR_RXDMAE                BIT(0)                  /* Receive DMA enable */
#define UARTPeriphID                    0xFE0                   /* Peripheral Identification Registers */
#define     PeriphID_PartNumber(X)      EXTRACT(X, 0, 0xFFF)
#define     PeriphID_Designer(X)        EXTRACT(X, 12, 0xFF)
#define     PeriphID_RevisionNumber(X)  EXTRACT(X, 20, 0xF)
#define     PeriphID_Configuration(X)   EXTRACT(X, 24, 0xFF)
#define UARTPCellID                     0xFF0                   /* PrimeCell Identification Registers */
#define     PCellID_0                   EXTRACT(X, 0, 0xFF)     /* 0x0D */
#define     PCellID_1                   EXTRACT(X, 8, 0xFF)     /* 0xF0 */
#define     PCellID_2                   EXTRACT(X, 16, 0xFF)    /* 0x05 */
#define     PCellID_3                   EXTRACT(X, 24, 0xFF)    /* 0xB1 */

#endif  //!__PL011__H__
