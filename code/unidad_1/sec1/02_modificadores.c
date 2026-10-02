#include <stdio.h>

int main(void) {
    unsigned int contador = 100u;
    short int nivel = 3;
    long int poblacion = 8000000000L;

    printf("Contador positivo: %u\n", contador);
    printf("Nivel: %hd\n", nivel);
    printf("Poblacion: %ld\n", poblacion);

    return 0;
}
