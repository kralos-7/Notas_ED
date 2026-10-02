#include <stdio.h>

typedef struct {
    int codigo;
    float precio;
} Producto;

int buscar_por_codigo(Producto inv[], int tam, int cod) {
    for (int i = 0; i < tam; i++) {
        if (inv[i].codigo == cod) return i;
    }
    return -1;
}

int main(void) {
    Producto inventario[30];
    inventario[0] = (Producto){501, 25.50f};
    inventario[1] = (Producto){502, 40.00f};

    int pos = buscar_por_codigo(inventario, 2, 502);
    if (pos != -1) printf("Producto encontrado: $%.2f\n", inventario[pos].precio);
    return 0;
}
