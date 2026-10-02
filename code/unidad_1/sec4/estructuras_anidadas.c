#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char titulo[100];
    Fecha fecha_publicacion;
} Libro;

int main(void) {
    Libro libro = {"Estructuras de Datos en C", {15, 9, 2026}};
    printf("Libro: %s (%02d/%02d/%d)\n", libro.titulo, 
            libro.fecha_publicacion.dia, 
            libro.fecha_publicacion.mes, 
            libro.fecha_publicacion.anio);
    return 0;
}
