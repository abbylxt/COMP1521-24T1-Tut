#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    // first convert them to binary
    // Hint: each number in hex, represents four bits in binary

    uint16_t a = 0x5555;
    //       5 = 4 + 1 = 2^2 + 2^0 = 0101
    //       a = 0101 0101 0101 0101 
    uint16_t b = 0xAAAA;// A = 10
    //     0xA = 10 = 2^3 + 2^1 = 1010
    //       b = 1010 1010 1010 1010
    uint16_t c = 0x0100;
    //       c = 0000 0000 0000 0001









    // a     = 0101 0101 0101 0101
    // b     = 1010 1010 1010 1010
    // a | b = 1111 1111 1111 1111
    printf("0x%04X\n", a | b); // 0xFFFF

    // a     = 0101 0101 0101 0101
    // b     = 1010 1010 1010 1010 
    // a & b = 0000 0000 0000 0000
    printf("0x%04X\n", a & b); // 0x0000

    // a     = 0101 0101 0101 0101
    // b     = 1010 1010 1010 1010 
    // a ^ b = 1111 1111 1111 1111
    printf("0x%X\n", a ^ b); // 0xFFFF

    // a     = 0101 0101 0101 0101 
    // ~b    = 0101 0101 0101 0101 
    // a & b = 0101 0101 0101 0101
    printf("0x%X\n", a & ~b); // 0x5555

    // c      = 0000 0000 0000 0001
    // c << 6 = 0000 0000 0100 0000
    printf("0x%04X\n", c << 6); // 0x0040

    // a      = 0101 0101 0101 0101 
    // a >> 4 = 0000 0101 0101 0101
    printf("0x%04X\n", a >> 4); // 0x0555

    // b            = 1010 1010 1010 1010 
    // 
    // b << 1       = 0101 0101 0101 0100 
    // a            = 0101 0101 0101 0101 
    // a & (b << 1) = 0101 0101 0101 0100
    printf("0x%04X\n", a & (b << 1)); // 0x5554

    // b            = 1010 1010 1010 1010  
    // c            = 0000 0000 0000 0001        c is a mask which isolates the last digit of the b
    // b & c        = 0000 0000 0000 0000 
    printf("0x%04X\n", b & c); // 0x0000

    // b            = 1010 1010 1010 1010  
    // c            = 0000 0001 0000 0000
    // b | c        = 1010 1011 1010 1011 
    printf("0x%04X\n", b | c); // 0xABAA   

    return EXIT_SUCCESS;
}