/*
 * SECCIÓN 5: Aplicación Práctica - Pila (LIFO) con Lista Enlazada
 * Compilar: gcc 04_aplicacion_pila.c -o pila
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoPila {
    int dato;
    struct NodoPila *siguiente;
} NodoPila;

void push(NodoPila **cima, int valor) {
    NodoPila *nuevo = (NodoPila*)malloc(sizeof(NodoPila));
    if (!nuevo) {
        printf("Error: Desbordamiento de memoria (Stack Overflow)\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cima;
    *cima = nuevo;
    printf("Push: %d\n", valor);
}

int pop(NodoPila **cima) {
    if (*cima == NULL) {
        printf("Error: Pila vacia (Stack Underflow)\n");
        return -1;
    }
    NodoPila *temp = *cima;
    int valor = temp->dato;
    *cima = (*cima)->siguiente;
    free(temp);
    return valor;
}

void mostrar_pila(NodoPila *cima) {
    NodoPila *actual = cima;
    printf("Estado de la Pila (Cima -> Base):\n");
    while (actual != NULL) {
        printf(" | %d |\n", actual->dato);
        actual = actual->siguiente;
    }
    printf(" -------\n");
}

void liberar_pila(NodoPila **cima) {
    while (*cima != NULL) {
        pop(cima);
    }
}

int main() {
    NodoPila *pila = NULL;

    printf("=== APLICACIÓN: PILA (LIFO) ===\n");
    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);

    mostrar_pila(pila);

    printf("\nElemento extraido (pop): %d\n", pop(&pila));
    mostrar_pila(pila);

    liberar_pila(&pila);
    return 0;
}