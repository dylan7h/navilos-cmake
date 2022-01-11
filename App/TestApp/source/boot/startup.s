.text
    .code 32

    .global vector_start
    .global vector_end

    vector_start:
        LDR PC, undef_handler_addr
        LDR PC, svc_handler_addr
        LDR PC, pftch_abt_handler_addr
        LDR PC, data_abt_handler_addr
        B   .
        LDR PC, irq_handler_addr
        LDR PC, fiq_handler_addr

        undef_handler_addr: .word reset_handler
        svc_handler_addr: .word svc_handler
        pftch_abt_handler_addr: .word pftch_abt_handler
        data_abt_handler_addr: .word data_abt_handler_handler
        irq_handler_addr: .word irq_handler_handler
        fiq_handler_addr: .word fiq_handler_handler
    vector_end:

    reset_handler:
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
    
    svc_handler:
    pftch_abt_handler:
    data_abt_handler_handler:
    irq_handler_handler:
    fiq_handler_handler:
    dummy_handler:
        B   .
.end
