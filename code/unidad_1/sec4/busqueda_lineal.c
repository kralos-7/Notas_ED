#include <stdio.h>

int buscar(int arr[], int tam, int clave) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == clave) return i;
    }
    return -1;
}

int main(void) {
    int datos[] = {15, 8, 42, 4, 23};
    int tam = 5;
    int pos = buscar(datos, tam, 42);
    if (pos != -1) printf("Encontrado en indice: %d\n", pos);
    return 0;
}
