#ifndef __ARMC7AR__H__
#define __ARMC7AR__H__

#define ARM_MODE_BIT_USR    0x10
#define ARM_MODE_BIT_FIQ    0x11
#define ARM_MODE_BIT_IRQ    0x12
#define ARM_MODE_BIT_SVC    0x13
#define ARM_MODE_BIT_ABT    0x17
#define ARM_MODE_BIT_UND    0x1B
#define ARM_MODE_BIT_SYS    0x1F
#define ARM_MODE_BIT_MON    0x16

#ifndef __ASM
#include <stdint.h>

typedef union __ARMv7AR_PSR
{
    uint32_t word;
    struct
    {
        uint32_t M      :   5;  /*  mode        encoding        PL(Privilege Level)        Implemented                          SS(Security State)
                                    USR         0x10            0                           Always                              Both
                                    FIQ         0x11            1                           Always                              Both
                                    IRQ         0x12            1                           Always                              Both
                                    SVC         0x13            1                           Always                              Both
                                    MON         0x16            1                           With Security Extensions            Secure only
                                    ABT         0x17            1                           Always                              Both
                                    HYP         0x1A            2                           With Virtualization Extensions      Non-secure only
                                    UND         0x1B            1                           Always                              Both
                                    SYS         0x1F            1                           Always                              Both
                                 */
        uint32_t T      :   1;  /* Thumb execution state bit 
                                    J   T
                                    0   0   ARM
                                    0   1   Thumb
                                    1   0   Jazelle
                                    1   1   ThumbEE
                                */

        /* Mask Bits 
            0 : Exception not masked
            1 : Exception masked
        */
        uint32_t F      :   1;  /* FIQ mask bit */
        uint32_t I      :   1;  /* IRQ mask bit */
        uint32_t A      :   1;  /* Asynchronous abort mask bit */

        uint32_t E      :   1;  /* Endianness execution state bit 
                                    0 : Little-endian operation
                                    1 : Big-endian operation
                                */
        uint32_t IT1    :   6;  /* IT[7:2] - If-Then execution state bits for the Thumb IT (If-Then) instruction. */
        uint32_t GE     :   4;  /* Greater than or Equal flags */
        uint32_t RES    :   4;
        uint32_t J      :   1;  /* Jazelle bit */
        uint32_t IT0    :   2;  /* IT[1:0] - If-Then execution state bits for the Thumb IT (If-Then) instruction. */

        uint32_t Q      :   1;  /* Cumulative saturation bit */

        /* Condition Flags */
        uint32_t V      :   1;  /* Overflow condition flag */
        uint32_t C      :   1;  /* Carry condition flag */
        uint32_t Z      :   1;  /* Zero condition flag */
        uint32_t N      :   1;  /* Negative condition flag */
    } bits;
} ARMv7AR_PSR_t;
#endif

#endif  //!__ARMC7AR__H__
