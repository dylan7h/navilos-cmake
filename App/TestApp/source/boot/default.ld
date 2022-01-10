ENTRY(vector_start)         /* Entry Symbol */
SECTIONS
{
    . = 0x00;               /* Start Address */

    .text :                 /* Code Region */
    {
        *(vector_start)
        *(.text .rodata)
    }
    .data :                 /* Initialized Global Varialbe */
    {
        *(.data)
    }
    .bss :                  /* Non Initialized Global Variable */
    {
        *(.bss)
    }
}
