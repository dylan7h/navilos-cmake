ENTRY(vector_start)
SECTIONS
{
    . = 0x00;

    .text :
    {
        *(vector_start)
        *(.text .rodata)
    }
    .data :
    {
        *(.data)
    }
    .bss :
    {
        *(.bss)
    }
}
