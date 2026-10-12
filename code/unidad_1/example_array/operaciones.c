#include <stdio.h>
#include <stdlib.h>

int buscar(int arr[], int tam, int clave) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == clave) {
            return i; // Elemento encontrado en índice i
        }
    }
    return -1; // No encontrado
}

void insertar(int arr[], int *tam, int pos, int valor) {
    // Desplazamiento a la derecha
    for (int i = *tam; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = valor;
    (*tam)++; // Incrementamos la cuenta de elementos
}

int eliminar(int arr[], int *tam, int valor) {
    // localiza el elemento
    int pos = buscar(arr,(*tam),valor);
    if(pos)
    {
        // Desplazamiento a la izquierda
        for (int i = pos; i < *tam; i++) {
            arr[i] = arr[i + 1];
        }
        arr[(*tam)] = 0;
        (*tam)--; // Decrementamos la cuenta de elementos
        return 1;
    }
    return 0; // No encontrado
}

void recorrido(int arr[], int tam) {

    for (int i = 0; i < tam; i++) {
        printf(" %d -> Valor = %d\n",i,arr[i]);
    }
    printf("----------------------\n");
    printf("Total de elementos: %d\n",tam);
}

void menu(){
	system("clear");
    printf("MENU\n");
    printf("1. Recorrer\n");
    printf("2. Insertar\n");
    printf("3. Eliminar\n");
    printf("4. Buscar\n");
    printf("5. Salir\n");
    printf("> ");
}
