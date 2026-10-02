#include <stdio.h>

typedef struct {
    int id;
    char nombre[50];
    float promedio;
} Alumno;

void imprimir_alumno(const Alumno *a) {
    printf("ID: %d | Promedio: %.2f\n", a->id, a->promedio);
}

int main(void) {
    Alumno a1 = {102, "Ana Lopez", 9.8f};
    a1.promedio = 10.0f;
    imprimir_alumno(&a1);
    return 0;
}
