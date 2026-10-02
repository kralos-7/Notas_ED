#include <stdlib.h>
#include "contador.h"

struct Contador {
    int valor;
};

Contador* contador_crear(int valor_inicial) {
    Contador* c = (Contador*) malloc(sizeof(Contador));
    if (c != NULL) {
        c->valor = valor_inicial;
    }
    return c;
}

void contador_incrementar(Contador* c) {
    if (c != NULL) {
        c->valor++;
    }
}

int contador_obtener_valor(const Contador* c) {
    return (c != NULL) ? c->valor : 0;
}

void contador_destruir(Contador* c) {
    free(c);
}
