#include <stdio.h>
#include "contador.h"

int main(void) {
    Contador* c = contador_crear(10);
    contador_incrementar(c);
    printf("Valor actual: %d\n", contador_obtener_valor(c));
    contador_destruir(c);
    return 0;
}
