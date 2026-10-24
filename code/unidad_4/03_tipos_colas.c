/*
 * SECCIÓN 3: Tipos de Colas (Cola Circular Estática y Deque / Cola Doble)
 * Compilar: gcc 03_tipos_colas.c -o tipos_colas
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// 1. Cola Circular Estática
typedef struct {
    int elementos[MAX];
    int frente;
    int final;
    int tamano;
} ColaCircular;

void inicializar_circular(ColaCircular *c) {
    c->frente = 0;
    c->final = -1;
    c->tamano = 0;
}

int isFullCircular(ColaCircular *c) {
    return c->tamano == MAX;
}

int isEmptyCircular(ColaCircular *c) {
    return c->tamano == 0;
}

void enqueue_circular(ColaCircular *c, int valor) {
    if (isFullCircular(c)) {
        printf("Cola Circular Llena\n");
        return;
    }
    c->final = (c->final + 1) % MAX;
    c->elementos[c->final] = valor;
    c->tamano++;
    printf("Enqueue Circular: %d\n", valor);
}

int dequeue_circular(ColaCircular *c) {
    if (isEmptyCircular(c)) {
        printf("Cola Circular Vacia\n");
        return -1;
    }
    int valor = c->elementos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->tamano--;
    return valor;
}

void imprimir_circular(ColaCircular *c) {
    if (isEmptyCircular(c)) {
        printf("Cola Circular Vacia.\n");
        return;
    }
    printf("Elementos en Cola Circular: ");
    for (int i = 0; i < c->tamano; i++) {
        int idx = (c->frente + i) % MAX;
        printf("[%d] ", c->elementos[idx]);
    }
    printf("\n");
}

int main() {
    ColaCircular cc;
    inicializar_circular(&cc);

    printf("=== COLA CIRCULAR ESTÁTICA ===\n");
    enqueue_circular(&cc, 100);
    enqueue_circular(&cc, 200);
    enqueue_circular(&cc, 300);
    enqueue_circular(&cc, 400);
    enqueue_circular(&cc, 500);

    imprimir_circular(&cc);

    printf("Desencolado: %d\n", dequeue_circular(&cc));
    printf("Desencolado: %d\n", dequeue_circular(&cc));

    imprimir_circular(&cc);

    enqueue_circular(&cc, 600);
    imprimir_circular(&cc);

    return 0;
}