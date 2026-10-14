#include <stdio.h>

int main(void) {
    int x = 42;
    int *ptr = &x;

    printf("=== Pointer Basics ===\n\n");

    printf("Value of x: %d\n", x);
    printf("Address of x (&x): %p\n", (void *)&x);
    printf("Value of ptr: %p\n", (void *)ptr);
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr);

    return 0;
}
