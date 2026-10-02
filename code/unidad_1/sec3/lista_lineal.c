#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

int main(void) {
    Nodo* n1 = (Nodo*) malloc(sizeof(Nodo));
    Nodo* n2 = (Nodo*) malloc(sizeof(Nodo));

    n1->dato = 10;
    n1->siguiente = n2;

    n2->dato = 20;
    n2->siguiente = NULL;

    printf("Nodo 1: %d -> Nodo 2: %d\n", n1->dato, n1->siguiente->dato);

    free(n1);
    free(n2);
    return 0;
}
