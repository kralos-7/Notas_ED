/*
 * SECCIÓN 4: Aplicaciones Prácticas (Validación de Delimitadores Balanceados)
 * Compilar: gcc 04_aplicaciones_pilas.c -o aplicaciones_pilas
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoChar {
    char dato;
    struct NodoChar *siguiente;
} NodoChar;

typedef struct {
    NodoChar *cima;
} PilaChar;

void inicializar_pila_char(PilaChar *p) {
    p->cima = NULL;
}

int isEmptyChar(PilaChar *p) {
    return p->cima == NULL;
}

void push_char(PilaChar *p, char val) {
    NodoChar *nuevo = (NodoChar*)malloc(sizeof(NodoChar));
    if (nuevo == NULL) return;
    nuevo->dato = val;
    nuevo->siguiente = p->cima;
    p->cima = nuevo;
}

char pop_char(PilaChar *p) {
    if (isEmptyChar(p)) return '\0';
    NodoChar *temp = p->cima;
    char val = temp->dato;
    p->cima = temp->siguiente;
    free(temp);
    return val;
}

int validar_parentesis(char *expresion) {
    PilaChar pila;
    inicializar_pila_char(&pila);

    for (int i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == '(' || c == '{' || c == '[') {
            push_char(&pila, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmptyChar(&pila)) return 0;
            char tope = pop_char(&pila);
            if ((c == ')' && tope != '(') ||
                (c == '}' && tope != '{') ||
                (c == ']' && tope != '[')) {
                return 0;
            }
        }
    }
    int balanceado = isEmptyChar(&pila);

    // Vaciar memoria restante si la pila no quedo vacia por error
    while (!isEmptyChar(&pila)) {
        pop_char(&pila);
    }

    return balanceado;
}

int main() {
    printf("=== APLICACIÓN: VALIDACIÓN DE DELIMITATEUR BALANCEADOS ===\n");

    char exp1[] = "{[()]}";
    char exp2[] = "{[(])}";
    char exp3[] = "((()";

    printf("Expresion: %-10s -> %s\n", exp1, validar_parentesis(exp1) ? "BALANCEADA" : "DESBALANCEADA");
    printf("Expresion: %-10s -> %s\n", exp2, validar_parentesis(exp2) ? "BALANCEADA" : "DESBALANCEADA");
    printf("Expresion: %-10s -> %s\n", exp3, validar_parentesis(exp3) ? "BALANCEADA" : "DESBALANCEADA");

    return 0;
}