/*
 * SECCIÓN 3: Operaciones con Listas Simplemente Enlazadas
 * Compilar: gcc 01_lista_simple_operaciones.c -o lista_simple
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

void insertar_inicio(Nodo **cabeza, int nuevo_dato) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = nuevo_dato;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void insertar_final(Nodo **cabeza, int nuevo_dato) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = nuevo_dato;
    nuevo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

void imprimir_lista(Nodo *cabeza) {
    Nodo *actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("[%d] -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

Nodo* buscar(Nodo *cabeza, int clave) {
    Nodo *actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == clave) return actual;
        actual = actual->siguiente;
    }
    return NULL;
}

void eliminar_inicio(Nodo **cabeza) {
    if (*cabeza == NULL) return;
    Nodo *temp = *cabeza;
    *cabeza = (*cabeza)->siguiente;
    free(temp);
}

void eliminar_valor(Nodo **cabeza, int clave) {
    Nodo *actual = *cabeza, *anterior = NULL;

    if (actual != NULL && actual->dato == clave) {
        *cabeza = actual->siguiente;
        free(actual);
        return;
    }

    while (actual != NULL && actual->dato != clave) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) return;

    anterior->siguiente = actual->siguiente;
    free(actual);
}

void liberar_lista(Nodo **cabeza) {
    Nodo *actual = *cabeza;
    Nodo *siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
}

int main() {
    Nodo *cabeza = NULL;

    printf("=== LISTA SIMPLEMENTE ENLAZADA ===\n");
    insertar_inicio(&cabeza, 10);
    insertar_inicio(&cabeza, 5);
    insertar_final(&cabeza, 20);
    imprimir_lista(cabeza); // [5] -> [10] -> [20] -> NULL

    printf("\nBuscando el elemento 10...\n");
    Nodo *hallado = buscar(cabeza, 10);
    if (hallado) printf("Encontrado: %d\n", hallado->dato);

    printf("\nEliminando el inicio...\n");
    eliminar_inicio(&cabeza);
    imprimir_lista(cabeza);

    printf("\nEliminando el valor 20...\n");
    eliminar_valor(&cabeza, 20);
    imprimir_lista(cabeza);

    liberar_lista(&cabeza);
    return 0;
}