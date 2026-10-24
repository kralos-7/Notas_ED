/*
 * SECCIÓN 1: Representación de una Pila (Estática vs Dinámica)
 * Compilar: gcc 01_representacion_pila.c -o representacion_pila
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// 1. Representación Estática basada en Arreglo
typedef struct {
    int elementos[MAX];
    int cima;
} PilaEstatica;

void inicializar_estatica(PilaEstatica *p) {
    p->cima = -1;
}

// 2. Representación Dinámica basada en Lista Enlazada
typedef struct NodoPila {
    int dato;
    struct NodoPila *siguiente;
} NodoPila;

typedef struct {
    NodoPila *cima;
} PilaDinamica;

void inicializar_dinamica(PilaDinamica *p) {
    p->cima = NULL;
}

int main() {
    printf("=== REPRESENTACIÓN DE PILAS EN C ===\n");

    // Demostración de estructura estática
    PilaEstatica pe;
    inicializar_estatica(&pe);
    printf("Pila estatica inicializada. Cima actual: %d (vacia)\n", pe.cima);

    // Demostración de estructura dinámica
    PilaDinamica pd;
    inicializar_dinamica(&pd);
    printf("Pila dinamica inicializada. Cima actual: %s\n", pd.cima == NULL ? "NULL (vacia)" : "No nula");

    return 0;
}