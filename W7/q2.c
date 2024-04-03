#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int16_t num1 = 0x0013; // 19
    int16_t num2 = 0x0444; // 1092
    int16_t num3 = 0x1234; // 4660
    int16_t num4 = 0xffff; // -1
    int16_t num5 = 0x8000; // -32768

    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);


    return EXIT_SUCCESS;
}