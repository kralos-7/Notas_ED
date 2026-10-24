/*
 * SECCIÓN 1: Representación de una Cola Dinámica y Estática
 * Compilar: gcc 01_representacion_cola.c -o representacion_cola
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// 1. Representación Estática (Arreglo Circular)
typedef struct {
    int elementos[MAX];
    int frente;
    int final;
    int tamano;
} ColaEstatica;

void inicializar_estatica(ColaEstatica *c) {
    c->frente = 0;
    c->final = -1;
    c->tamano = 0;
}

// 2. Representación Dinámica (Lista Enlazada)
typedef struct NodoCola {
    int dato;
    struct NodoCola *siguiente;
} NodoCola;

typedef struct {
    NodoCola *frente;
    NodoCola *final;
} ColaDinamica;

void inicializar_dinamica(ColaDinamica *c) {
    c->frente = NULL;
    c->final = NULL;
}

int main() {
    printf("=== REPRESENTACIÓN DE COLAS EN C ===\n");

    // Estructura estática
    ColaEstatica ce;
    inicializar_estatica(&ce);
    printf("Cola estatica inicializada. Tamano actual: %d\n", ce.tamano);

    // Estructura dinámica
    ColaDinamica cd;
    inicializar_dinamica(&cd);
    printf("Cola dinamica inicializada. Frente: %s, Final: %s\n", 
           cd.frente == NULL ? "NULL" : "OK",
           cd.final == NULL ? "NULL" : "OK");

    return 0;
}