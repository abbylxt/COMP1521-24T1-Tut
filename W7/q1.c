#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int16_t num1 = 30000; 
    int16_t num2 = 30000;
    int32_t result = num1 + num2;
    uint16_t unsigned_result = num1 + num2;

    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", result);
    printf("%d\n", unsigned_result);


    return EXIT_SUCCESS;
}