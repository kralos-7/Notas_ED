#include <stdio.h>

void modificar(int arr[], int tam) {
    for (int i = 0; i < tam; i++) arr[i] *= 2;
}

int main(void) {
    int valores[] = {1, 2, 3, 4, 5};
    modificar(valores, 5);
    for (int i = 0; i < 5; i++) printf("%d ", valores[i]);
    printf("\n");
    return 0;
}
