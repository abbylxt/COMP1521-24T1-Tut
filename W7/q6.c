#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {
    u = u >> 13;
    uint32_t mask = 0x3f;
    u = mask & u; 
    // 0b 11 1111
    return u;
}

int main(void) {
    uint32_t num = 0x00F9AEB0; // 0b 0000 0000 1111 1001 1010 1110 1011 0000
// mid six = 01 0111
// hex = 0x17
    printf("%d\n", num);
    printf("0x%0x\n", six_middle_bits(num));
    return EXIT_SUCCESS;
}