/*
 * SECCIÓN 4: Aplicación Práctica (Simulación de Búfer / Impresión FIFO)
 * Compilar: gcc 04_aplicaciones_colas.c -o aplicaciones_colas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrabajoImpresion {
    int id;
    char nombre_archivo[50];
    struct TrabajoImpresion *siguiente;
} TrabajoImpresion;

typedef struct {
    TrabajoImpresion *frente;
    TrabajoImpresion *final;
} ColaImpresion;

void inicializar_impresora(ColaImpresion *c) {
    c->frente = NULL;
    c->final = NULL;
}

void agregar_trabajo(ColaImpresion *c, int id, const char *archivo) {
    TrabajoImpresion *nuevo = (TrabajoImpresion*)malloc(sizeof(TrabajoImpresion));
    nuevo->id = id;
    strncpy(nuevo->nombre_archivo, archivo, sizeof(nuevo->nombre_archivo));
    nuevo->siguiente = NULL;

    if (c->frente == NULL) {
        c->frente = nuevo;
        c->final = nuevo;
    } else {
        c->final->siguiente = nuevo;
        c->final = nuevo;
    }
    printf("Trabajo recibido -> ID: %d | Archivo: %s\n", id, archivo);
}

void procesar_trabajo(ColaImpresion *c) {
    if (c->frente == NULL) {
        printf("No hay trabajos pendientes de impresion.\n");
        return;
    }
    TrabajoImpresion *temp = c->frente;
    printf("Imprimiendo -> ID: %d | Archivo: %s ... ¡Completado!\n", temp->id, temp->nombre_archivo);

    c->frente = temp->siguiente;
    if (c->frente == NULL) {
        c->final = NULL;
    }
    free(temp);
}

int main() {
    ColaImpresion spooler;
    inicializar_impresora(&spooler);

    printf("=== SIMULADOR DE COLA DE IMPRESIÓN (PRINT SPOOLER) ===\n");
    agregar_trabajo(&spooler, 1, "Reporte_Final.pdf");
    agregar_trabajo(&spooler, 2, "Syllabus_Curso.docx");
    agregar_trabajo(&spooler, 3, "Grafico_Estadisticas.png");

    printf("\n--- Procesando Trabajos en Orden FIFO ---\n");
    procesar_trabajo(&spooler);
    procesar_trabajo(&spooler);

    printf("\n--- Agregando Nuevo Trabajo ---\n");
    agregar_trabajo(&spooler, 4, "Examen_Parcial.pdf");

    printf("\n--- Procesando Restantes ---\n");
    procesar_trabajo(&spooler);
    procesar_trabajo(&spooler);
    procesar_trabajo(&spooler);

    return 0;
}