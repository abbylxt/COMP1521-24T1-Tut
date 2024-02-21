#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= 100) goto else_s;
    if (x >= 1000) goto else_s;
    printf("medium\n");
    goto else_end;
    else_s:
    printf("small/big\n");
    else_end:
}