#include <stdio.h>

void insertar(int arr[], int *tam, int pos, int valor) {
    for (int i = *tam; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = valor;
    (*tam)++;
}

int main(void) {
    int arr[10] = {10, 20, 40, 50};
    int tam = 4;
    insertar(arr, &tam, 2, 30);
    printf("Arreglo: ");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
