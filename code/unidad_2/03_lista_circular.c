/*
 * SECCIÓN 4: Listas Circulares Simples
 * Compilar: gcc 03_lista_circular.c -o lista_circular
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoCircular {
    int dato;
    struct NodoCircular *siguiente;
} NodoCircular;

void insertar_circular(NodoCircular **cabeza, int nuevo_dato) {
    NodoCircular *nuevo = (NodoCircular*)malloc(sizeof(NodoCircular));
    nuevo->dato = nuevo_dato;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        nuevo->siguiente = *cabeza;
        return;
    }

    NodoCircular *actual = *cabeza;
    while (actual->siguiente != *cabeza) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->siguiente = *cabeza;
}

void imprimir_circular(NodoCircular *cabeza) {
    if (cabeza == NULL) {
        printf("Lista circular vacia\n");
        return;
    }

    NodoCircular *actual = cabeza;
    printf("Lista Circular: ");
    do {
        printf("[%d] -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(Regresa a Cabeza: %d)\n", cabeza->dato);
}

void liberar_circular(NodoCircular **cabeza) {
    if (*cabeza == NULL) return;

    NodoCircular *actual = *cabeza;
    NodoCircular *sig = NULL;

    do {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    } while (actual != *cabeza);

    *cabeza = NULL;
}

int main() {
    NodoCircular *cabeza = NULL;

    printf("=== LISTA CIRCULAR ===\n");
    insertar_circular(&cabeza, 100);
    insertar_circular(&cabeza, 200);
    insertar_circular(&cabeza, 300);

    imprimir_circular(cabeza);

    liberar_circular(&cabeza);
    return 0;
}