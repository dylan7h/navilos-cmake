.text
    .code 32

    .global vector_start
    .global vector_end

    vector_start:
        /*
            [ SYS_ID Register ]

           31  28 27        16 15 12 11 8 7      0
            +++++++++++++++++++++++++++++++++++++++
            + REV+     HBI    +BUILD+ARCH+  FPGA  +
            +++++++++++++++++++++++++++++++++++++++
              0x00    0x178     0x0   0x5    0x00
         */
        LDR R0, =0x10000000 /* R0 = 0x10000000 */
        LDR R1, [R0]        /* R1 = *(uint32_t*)0x10000000 --> 0x1780500*/
    vector_end:
        .space 1024, 0
.end
