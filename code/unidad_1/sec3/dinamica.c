#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;
    int* arreglo_dinamico = (int*) malloc(n * sizeof(int));

    if (arreglo_dinamico != NULL) {
        arreglo_dinamico[0] = 100;
        printf("Primer elemento dinámico: %d\n", arreglo_dinamico[0]);
        free(arreglo_dinamico);
    }
    return 0;
}
