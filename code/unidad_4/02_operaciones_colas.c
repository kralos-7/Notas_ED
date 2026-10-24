/*
 * SECCIÓN 2: Operaciones Fundamentales con Colas Dinámicas (Enqueue, Dequeue, Peek, isEmpty)
 * Compilar: gcc 02_operaciones_colas.c -o operaciones_colas
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoCola {
    int dato;
    struct NodoCola *siguiente;
} NodoCola;

typedef struct {
    NodoCola *frente;
    NodoCola *final;
} ColaDinamica;

void inicializar(ColaDinamica *c) {
    c->frente = NULL;
    c->final = NULL;
}

int isEmpty(ColaDinamica *c) {
    return c->frente == NULL;
}

void enqueue(ColaDinamica *cola, int valor) {
    NodoCola *nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    if (nuevo == NULL) {
        printf("Error: Memoria llena (Overflow)\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (cola->frente == NULL) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    printf("Enqueue: %d\n", valor);
}

int dequeue(ColaDinamica *cola) {
    if (isEmpty(cola)) {
        printf("Error: Cola vacia (Underflow)\n");
        return -1;
    }
    NodoCola *temp = cola->frente;
    int valor_extraido = temp->dato;

    cola->frente = temp->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    free(temp);
    return valor_extraido;
}

int peek(ColaDinamica *cola) {
    if (isEmpty(cola)) {
        printf("La cola esta vacia.\n");
        return -1;
    }
    return cola->frente->dato;
}

void imprimir_cola(ColaDinamica *cola) {
    if (isEmpty(cola)) {
        printf("Cola vacia.\n");
        return;
    }
    NodoCola *actual = cola->frente;
    printf("Estado de la Cola (Frente -> Final): ");
    while (actual != NULL) {
        printf("[%d] -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void liberar_cola(ColaDinamica *cola) {
    while (!isEmpty(cola)) {
        dequeue(cola);
    }
}

int main() {
    ColaDinamica cola;
    inicializar(&cola);

    printf("=== OPERACIONES CON COLAS ===\n");
    enqueue(&cola, 10);
    enqueue(&cola, 20);
    enqueue(&cola, 30);

    imprimir_cola(&cola);

    printf("Frente actual (peek): %d\n\n", peek(&cola));

    printf("Elemento desencolado (dequeue): %d\n", dequeue(&cola));
    imprimir_cola(&cola);

    printf("Elemento desencolado (dequeue): %d\n", dequeue(&cola));
    imprimir_cola(&cola);

    liberar_cola(&cola);
    return 0;
}