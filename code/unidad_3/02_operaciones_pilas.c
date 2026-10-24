/*
 * SECCIÓN 2: Operaciones Fundamentales con Pilas Dinámicas (Push, Pop, Peek, isEmpty)
 * Compilar: gcc 02_operaciones_pilas.c -o operaciones_pilas
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoPila {
    int dato;
    struct NodoPila *siguiente;
} NodoPila;

typedef struct {
    NodoPila *cima;
} PilaDinamica;

void inicializar(PilaDinamica *p) {
    p->cima = NULL;
}

int isEmpty(PilaDinamica *p) {
    return p->cima == NULL;
}

void push(PilaDinamica *pila, int valor) {
    NodoPila *nuevo = (NodoPila*)malloc(sizeof(NodoPila));
    if (nuevo == NULL) {
        printf("Error: Stack Overflow (Memoria llena)\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = pila->cima;
    pila->cima = nuevo;
    printf("Push: %d\n", valor);
}

int pop(PilaDinamica *pila) {
    if (isEmpty(pila)) {
        printf("Error: Stack Underflow (Pila vacia)\n");
        return -1;
    }
    NodoPila *temp = pila->cima;
    int valor_extraido = temp->dato;

    pila->cima = temp->siguiente;
    free(temp);

    return valor_extraido;
}

int peek(PilaDinamica *pila) {
    if (isEmpty(pila)) {
        printf("La pila esta vacia.\n");
        return -1;
    }
    return pila->cima->dato;
}

void imprimir_pila(PilaDinamica *pila) {
    if (isEmpty(pila)) {
        printf("Pila vacia.\n");
        return;
    }
    NodoPila *actual = pila->cima;
    printf("Estado de la Pila (Cima -> Base):\n");
    while (actual != NULL) {
        printf(" | %d |\n", actual->dato);
        actual = actual->siguiente;
    }
    printf(" -------\n");
}

void liberar_pila(PilaDinamica *pila) {
    while (!isEmpty(pila)) {
        pop(pila);
    }
}

int main() {
    PilaDinamica pila;
    inicializar(&pila);

    printf("=== OPERACIONES CON PILAS ===\n");
    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);

    imprimir_pila(&pila);

    printf("Cima actual (peek): %d\n\n", peek(&pila));

    printf("Elemento extraido (pop): %d\n", pop(&pila));
    imprimir_pila(&pila);

    printf("Elemento extraido (pop): %d\n", pop(&pila));
    imprimir_pila(&pila);

    liberar_pila(&pila);
    return 0;
}