#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int16_t num_i = 0x0001; // 1
    int16_t num_ii = 0x0064; // 
    int16_t num_iv = 0x2710; // 
    int16_t num_vi = 0xfffb; // -5
    int16_t num_vii = 0xff9e; // 

    printf("%d\n", num_i);
    printf("%d\n", num_ii);
    printf("%d\n", num_iv);
    printf("%d\n", num_vi);
    printf("%d\n", num_vii);


    return EXIT_SUCCESS;
}