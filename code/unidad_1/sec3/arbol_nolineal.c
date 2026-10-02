#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol {
    int dato;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
} NodoArbol;

NodoArbol* crear_nodo(int dato) {
    NodoArbol* nuevo = (NodoArbol*) malloc(sizeof(NodoArbol));
    if (nuevo != NULL) {
        nuevo->dato = dato;
        nuevo->izquierdo = NULL;
        nuevo->derecho = NULL;
    }
    return nuevo;
}

int main(void) {
    NodoArbol* raiz = crear_nodo(10);
    raiz->izquierdo = crear_nodo(5);
    raiz->derecho = crear_nodo(15);

    printf("Raiz: %d\n", raiz->dato);
    printf("Hijo Izquierdo: %d | Hijo Derecho: %d\n", 
            raiz->izquierdo->dato, raiz->derecho->dato);

    free(raiz->izquierdo);
    free(raiz->derecho);
    free(raiz);
    return 0;
}
