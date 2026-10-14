#include <stdio.h>

int main(void) {
    int num = 10;
    int *ptr = &num;

    printf("=== Modify Value Through Pointer ===\n\n");

    printf("Original value of num: %d\n", num);

    *ptr = 20;

    printf("Modified value of num: %d\n", num);

    return 0;
}
