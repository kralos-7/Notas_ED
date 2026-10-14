#include <stdio.h>

void swap_values(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 5;
    int y = 10;

    printf("=== Swap Values ===\n\n");

    printf("Before swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    swap_values(&x, &y);

    printf("\nAfter swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
