#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Punto Punto;

struct Punto {
    double x;
    double y;
};

Punto* punto_crear(double x, double y) {
    Punto* p = (Punto*) malloc(sizeof(Punto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

double punto_obtener_x(const Punto* p) { return (p != NULL) ? p->x : 0.0; }
double punto_obtener_y(const Punto* p) { return (p != NULL) ? p->y : 0.0; }

double punto_distancia_origen(const Punto* p) {
    if (p == NULL) return 0.0;
    return sqrt((p->x * p->x) + (p->y * p->y));
}

void punto_destruir(Punto* p) { free(p); }

int main(void) {
    Punto* p = punto_crear(3.0, 4.0);
    printf("Punto: (%.1f, %.1f)\n", punto_obtener_x(p), punto_obtener_y(p));
    printf("Distancia al origen: %.2f\n", punto_distancia_origen(p));
    punto_destruir(p);
    return 0;
}
