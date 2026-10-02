#include <stdio.h>

typedef struct {
    int id;
    char nombre[50];
    float promedio;
} Alumno;

int main(void) {
    Alumno a1 = {101, "Carlos Rojas", 9.5f};
    printf("ID: %d, Nombre: %s, Promedio: %.1f\n", a1.id, a1.nombre, a1.promedio);
    return 0;
}
