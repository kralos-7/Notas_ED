/*
 * SECCIÓN 3: Notación Infija, Postfija (Evaluación y Conversión Shunting-Yard)
 * Compilar: gcc 03_notacion_expresiones.c -o notacion_expresiones
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Pila de Enteros para Evaluación
typedef struct NodoInt {
    int dato;
    struct NodoInt *sig;
} NodoInt;

typedef struct {
    NodoInt *cima;
} PilaInt;

void push_int(PilaInt *p, int val) {
    NodoInt *nuevo = (NodoInt*)malloc(sizeof(NodoInt));
    nuevo->dato = val;
    nuevo->sig = p->cima;
    p->cima = nuevo;
}

int pop_int(PilaInt *p) {
    if (p->cima == NULL) return 0;
    NodoInt *t = p->cima;
    int v = t->dato;
    p->cima = t->sig;
    free(t);
    return v;
}

// Pila de Caracteres para Conversión
typedef struct NodoChar {
    char dato;
    struct NodoChar *sig;
} NodoChar;

typedef struct {
    NodoChar *cima;
} PilaChar;

void push_char(PilaChar *p, char val) {
    NodoChar *nuevo = (NodoChar*)malloc(sizeof(NodoChar));
    nuevo->dato = val;
    nuevo->sig = p->cima;
    p->cima = nuevo;
}

char pop_char(PilaChar *p) {
    if (p->cima == NULL) return '\0';
    NodoChar *t = p->cima;
    char v = t->dato;
    p->cima = t->sig;
    free(t);
    return v;
}

char peek_char(PilaChar *p) {
    return (p->cima == NULL) ? '\0' : p->cima->dato;
}

int isEmptyChar(PilaChar *p) {
    return p->cima == NULL;
}

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infija_a_postfija(char *infija, char *postfija) {
    PilaChar pila = {NULL};
    int j = 0;

    for (int i = 0; infija[i] != '\0'; i++) {
        char c = infija[i];
        if (c == ' ' || c == '\t') continue;

        if (isalnum(c)) {
            postfija[j++] = c;
        } else if (c == '(') {
            push_char(&pila, c);
        } else if (c == ')') {
            while (!isEmptyChar(&pila) && peek_char(&pila) != '(') {
                postfija[j++] = pop_char(&pila);
            }
            pop_char(&pila);
        } else {
            while (!isEmptyChar(&pila) && precedencia(peek_char(&pila)) >= precedencia(c)) {
                postfija[j++] = pop_char(&pila);
            }
            push_char(&pila, c);
        }
    }
    while (!isEmptyChar(&pila)) {
        postfija[j++] = pop_char(&pila);
    }
    postfija[j] = '\0';
}

int evaluar_postfija(char *expresion) {
    PilaInt pila = {NULL};

    for (int i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == ' ' || c == '\t') continue;

        if (isdigit(c)) {
            push_int(&pila, c - '0');
        } else {
            int op2 = pop_int(&pila);
            int op1 = pop_int(&pila);
            switch (c) {
                case '+': push_int(&pila, op1 + op2); break;
                case '-': push_int(&pila, op1 - op2); break;
                case '*': push_int(&pila, op1 * op2); break;
                case '/': push_int(&pila, op1 / op2); break;
            }
        }
    }
    return pop_int(&pila);
}

int main() {
    char infija[] = "5+(3*2)-8";
    char postfija[100];

    printf("=== CONVERSIÓN Y EVALUACIÓN DE EXPRESIONES ===\n");
    printf("Expresion Infija: %s\n", infija);

    infija_a_postfija(infija, postfija);
    printf("Expresion Postfija: %s\n", postfija);

    char postfija_eval[] = "532*+8-";
    int resultado = evaluar_postfija(postfija_eval);
    printf("Evaluacion de '%s' = %d\n", postfija_eval, resultado);

    return 0;
}