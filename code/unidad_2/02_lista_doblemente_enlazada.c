/*
 * SECCIÓN 4: Listas Doblemente Enlazadas
 * Compilar: gcc 02_lista_doblemente_enlazada.c -o lista_doble
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoDoble {
    int dato;
    struct NodoDoble *anterior;
    struct NodoDoble *siguiente;
} NodoDoble;

void insertar_inicio_doble(NodoDoble **cabeza, int nuevo_dato) {
    NodoDoble *nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
    nuevo->dato = nuevo_dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = *cabeza;

    if (*cabeza != NULL) {
        (*cabeza)->anterior = nuevo;
    }
    *cabeza = nuevo;
}

void imprimir_adelante(NodoDoble *cabeza) {
    NodoDoble *actual = cabeza;
    printf("Hacia adelante: NULL <-> ");
    while (actual != NULL) {
        printf("[%d] <-> ", actual->dato);
        if (actual->siguiente == NULL) break;
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void liberar_doble(NodoDoble **cabeza) {
    NodoDoble *actual = *cabeza;
    NodoDoble *sig = NULL;
    while (actual != NULL) {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    }
    *cabeza = NULL;
}

int main() {
    NodoDoble *cabeza = NULL;

    printf("=== LISTA DOBLEMENTE ENLAZADA ===\n");
    insertar_inicio_doble(&cabeza, 30);
    insertar_inicio_doble(&cabeza, 20);
    insertar_inicio_doble(&cabeza, 10);

    imprimir_adelante(cabeza);

    liberar_doble(&cabeza);
    return 0;
}