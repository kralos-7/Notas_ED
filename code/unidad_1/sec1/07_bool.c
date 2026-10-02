#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool activo = true;
    bool completado = false;

    if (activo) {
        printf("El sistema esta activo (%d)\n", activo);
    }
    printf("Estado completado: %d\n", completado);
    return 0;
}
