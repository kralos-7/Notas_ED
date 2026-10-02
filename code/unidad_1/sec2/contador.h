#ifndef CONTADOR_H
#define CONTADOR_H

typedef struct Contador Contador;

Contador* contador_crear(int valor_inicial);
void contador_incrementar(Contador* c);
int contador_obtener_valor(const Contador* c);
void contador_destruir(Contador* c);

#endif
