#include <stdint.h>
#include <stdio.h>


int main(void)
{

    uint32_t data[2] = { 0x12345678, 0x10203040 };

    uint32_t *word_ptr = data;
    uint8_t *byte_ptr = (uint8_t *)data;

    printf("--------------Endianness----------------\n");
    printf("\n--------------data addr-----------------\n");
    printf("%p ", data);
    printf("points to array [%x, %x]\n", data[0], data[1]);

    printf("\n--------------word_ptr------------------\n");
    printf("%p ", word_ptr);
    printf("points to ");
    printf("%x\n", *word_ptr);

    printf("\n--------------word_ptr + 1--------------\n");
    printf("%p ", word_ptr + 1);
    printf("points to ");
    printf("%x\n", *(word_ptr + 1));

    printf("\n--------------byte_ptr------------------\n");
    printf("%p ", byte_ptr);
    printf("points to ");
    printf("%x\n", *byte_ptr);

    printf("\n--------------byte_ptr + 3--------------\n");
    printf("%p ", byte_ptr + 3);
    printf("points to ");
    printf("%x\n", *(byte_ptr + 3));

    printf("\n----------------------------------------\n");
    return 0;
}

