#include <stdio.h>
#include <stdint.h>
typedef unsigned int Word;

Word reverseBits(Word w) {
    Word result = 0;
    for (int bit = 0; bit < 32; bit++) {
        Word mask = 1;
        Word curr_bit = w & mask;
        result = result | (curr_bit  << (31 - bit));
        w = w >> 1;
    }
    return result;
}
// 0000 0001 0010 0011 0100 0101 0110 0111
// 1110 0110 1010 0010 1100 0100 1000 0000
// testing
int main(void) {
    Word w1 = 0x01234567;
    // 0 = 0000 => 0000 = 0
    // 1 = 0001 => 1000 = 8
    // 2 = 0010 => 0100 = 4
    // 3 = 0011 => 1100 = C
    // 4 = 0100 => 0010 = 2
    // 5 = 0101 => 1010 = A
    // 6 = 0110 => 0110 = 6
    // 7 = 0111 => 1110 = E
    // assert(reverseBits(w1) == 0xE6A2C480);
    printf("0x%X\n", reverseBits(w1));
    // puts("All tests passed!");
    return 0;
}