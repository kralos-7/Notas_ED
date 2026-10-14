
#include <stdio.h>

// Funcion que modifica el valor de una variable mediante
// un puntero doble.
//
// ptr_doble recibe la direccion de un puntero de tipo int *.
// Al utilizar *ptr_doble accedemos al puntero original.
// Al utilizar **ptr_doble accedemos al valor del entero.
void modificar_valor(int **ptr_doble, int nuevo_valor) {
    **ptr_doble = nuevo_valor;
}

// Funcion que cambia el destino de un puntero.
//
// ptr_doble recibe la direccion del puntero original.
// nuevo_destino contiene la direccion de otra variable.
// Al asignar *ptr_doble = nuevo_destino, cambiamos el
// destino del puntero original desde esta funcion.
void cambiar_puntero(int **ptr_doble, int *nuevo_destino) {
    *ptr_doble = nuevo_destino;
}

// Funcion que muestra el valor de un entero a traves
// de un puntero doble.
void mostrar_valor(int **ptr_doble) {
    printf("Valor: %d\n", **ptr_doble);
}

int main(void) {
    printf("=== Double Pointers ===\n");

    // --------------------------------------------------
    // 1. Declaracion de una variable, un puntero y
    //    un puntero doble.
    // --------------------------------------------------

    int x = 10;

    // ptr almacena la direccion de memoria de x.
    int *ptr = &x;

    // ptr_doble almacena la direccion de memoria de ptr.
    // Por eso, ptr_doble es un puntero a otro puntero.
    int **ptr_doble = &ptr;

    printf("\n1. Declaracion de un puntero doble:\n");
    printf("Valor de x: %d\n", x);
    printf("Valor de *ptr: %d\n", *ptr);
    printf("Valor de **ptr_doble: %d\n", **ptr_doble);

    // --------------------------------------------------
    // 2. Comprender los niveles de indirecccion.
    // --------------------------------------------------

    printf("\n2. Direcciones de memoria:\n");

    // &x es la direccion de la variable x.
    printf("Direccion de x (&x): %p\n", (void *)&x);

    // ptr contiene la direccion de x.
    printf("Valor de ptr: %p\n", (void *)ptr);

    // &ptr es la direccion de memoria del propio puntero.
    printf("Direccion de ptr (&ptr): %p\n", (void *)&ptr);

    // ptr_doble contiene la direccion de ptr.
    printf("Valor de ptr_doble: %p\n", (void *)ptr_doble);

    // *ptr_doble obtiene el valor almacenado en ptr,
    // es decir, la direccion de x.
    printf("Valor de *ptr_doble: %p\n", (void *)*ptr_doble);

    // --------------------------------------------------
    // 3. Modificar x utilizando un puntero doble.
    // --------------------------------------------------

    printf("\n3. Modificar un valor mediante un puntero doble:\n");
    printf("Valor original de x: %d\n", x);

    // **ptr_doble permite llegar hasta el entero x.
    // La asignacion modifica directamente la variable.
    **ptr_doble = 25;

    printf("Nuevo valor de x: %d\n", x);

    // --------------------------------------------------
    // 4. Modificar un valor mediante una funcion.
    // --------------------------------------------------

    printf("\n4. Modificar un valor mediante una funcion:\n");
    printf("Valor antes de llamar a la funcion: %d\n", x);

    // Enviamos &ptr, es decir, la direccion del puntero.
    // La funcion puede acceder a x mediante **ptr_doble.
    modificar_valor(&ptr, 50);

    printf("Valor despues de llamar a la funcion: %d\n", x);

    // --------------------------------------------------
    // 5. Cambiar el destino del puntero.
    // --------------------------------------------------

    int y = 100;

    printf("\n5. Cambiar el destino de un puntero:\n");

    // En este momento, ptr apunta a x.
    ptr = &x;

    printf("Antes del cambio:\n");
    printf("Valor apuntado por ptr: %d\n", *ptr);
    printf("Direccion almacenada en ptr: %p\n", (void *)ptr);

    // Enviamos la direccion del puntero ptr y la direccion
    // de y. La funcion cambia ptr para que apunte a y.
    cambiar_puntero(&ptr, &y);

    printf("\nDespues del cambio:\n");
    printf("Valor apuntado por ptr: %d\n", *ptr);
    printf("Direccion almacenada en ptr: %p\n", (void *)ptr);

    // Ahora *ptr modifica y, no x.
    *ptr = 200;

    printf("Nuevo valor de y: %d\n", y);
    printf("Valor de x sin cambios: %d\n", x);

    // --------------------------------------------------
    // 6. Mostrar un valor mediante una funcion.
    // --------------------------------------------------

    printf("\n6. Mostrar un valor mediante un puntero doble:\n");

    // ptr apunta actualmente a y.
    // &ptr es la direccion del puntero que enviamos.
    mostrar_valor(&ptr);

    // --------------------------------------------------
    // 7. Arreglo de punteros.
    // --------------------------------------------------

    int a = 11;
    int b = 22;
    int c = 33;

    // Cada elemento del arreglo almacena la direccion
    // de una variable de tipo int.
    int *punteros[3] = {&a, &b, &c};

    printf("\n7. Recorrido de un arreglo de punteros:\n");

    for (int i = 0; i < 3; i++) {
        // punteros[i] obtiene una direccion de memoria.
        // *punteros[i] obtiene el entero correspondiente.
        printf("Elemento %d: %d\n", i, *punteros[i]);
    }

    // --------------------------------------------------
    // 8. Puntero doble aplicado a un arreglo de punteros.
    // --------------------------------------------------

    // punteros es un arreglo de elementos int *.
    // En esta inicializacion, punteros equivale a la
    // direccion de su primer elemento.
    int **pp = punteros;

    printf("\n8. Recorrido mediante un puntero doble:\n");

    for (int i = 0; i < 3; i++) {
        // *(pp + i) obtiene el puntero de la posicion i.
        // **(pp + i) obtiene el entero al que apunta.
        printf("Elemento %d: %d\n", i, **(pp + i));
    }

    // --------------------------------------------------
    // 9. Modificar valores mediante el arreglo de punteros.
    // --------------------------------------------------

    printf("\n9. Modificar valores mediante punteros dobles:\n");

    // pp apunta al primer elemento de punteros.
    // **pp modifica la variable a.
    **pp = 111;

    // *(pp + 1) es el segundo puntero del arreglo.
    // **(pp + 1) modifica la variable b.
    **(pp + 1) = 222;

    // *(pp + 2) es el tercer puntero del arreglo.
    // **(pp + 2) modifica la variable c.
    **(pp + 2) = 333;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}
