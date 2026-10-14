#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};
    int *ptr = numbers;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("=== Pointers and Arrays ===\n");

    // 1. Recorrido directo utilizando indices del arreglo
    printf("\n1. Forward traversal using indexes:\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    // 2. Recorrido directo utilizando aritmetica de punteros
    printf("\n\n2. Forward traversal using pointer arithmetic:\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }

    // 3. Recorrido directo utilizando un puntero que avanza
    printf("\n\n3. Forward traversal using a pointer:\n");

    for (int *p = numbers; p < numbers + size; p++) {
        printf("%d ", *p);
    }

    // 4. Recorrido inverso utilizando indices del arreglo
    printf("\n\n4. Backward traversal using indexes:\n");

    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }

    // 5. Recorrido inverso utilizando aritmetica de punteros
    printf("\n\n5. Backward traversal using pointer arithmetic:\n");

    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", *(ptr + i));
    }

    // 6. Acceso individual a elementos mediante un puntero
    printf("\n\n6. Accessing individual elements:\n");

    printf("First element: %d\n", *ptr);
    printf("Third element: %d\n", *(ptr + 2));
    printf("Last element: %d\n", *(ptr + size - 1));

    printf("\n");

    return 0;
}
