#include <stdio.h>

// Definicion de una estructura para representar un estudiante
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Funcion que muestra los datos de un estudiante mediante un puntero
void show_student(const Student *ptr) {
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Grade: %.2f\n", ptr->grade);
}

// Funcion que modifica la calificacion mediante un puntero
void update_grade(Student *ptr, float new_grade) {
    ptr->grade = new_grade;
}

int main(void) {
    // 1. Declaracion de una estructura y un puntero
    Student student = {1, "Carlos", 9.5};
    Student *ptr = &student;

    printf("=== Pointers to Structures ===\n");

    // 2. Acceso a los miembros mediante el operador flecha
    printf("\n1. Acceso mediante el operador ->:\n");
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Grade: %.2f\n", ptr->grade);

    // 3. Acceso mediante desreferenciacion y el operador punto
    // (*ptr) obtiene la estructura a la que apunta el puntero
    printf("\n2. Acceso mediante (*ptr).miembro:\n");
    printf("ID: %d\n", (*ptr).id);
    printf("Name: %s\n", (*ptr).name);
    printf("Grade: %.2f\n", (*ptr).grade);

    // 4. Modificacion de los miembros mediante el puntero
    printf("\n3. Modificacion de datos:\n");
    ptr->grade = 10.0;
    printf("New grade: %.2f\n", student.grade);

    // 5. Envio del puntero a una funcion
    // La funcion recibe la direccion de la estructura original
    printf("\n4. Mostrar datos mediante una funcion:\n");
    show_student(ptr);

    // 6. Modificacion de datos mediante una funcion
    printf("\n5. Actualizar calificacion mediante una funcion:\n");
    update_grade(ptr, 8.7);
    printf("Updated grade: %.2f\n", student.grade);

    // 7. Declaracion de un arreglo de estructuras
    Student students[3] = {
        {2, "Ana", 9.2},
        {3, "Luis", 8.5},
        {4, "Maria", 9.8}
    };

    // 8. Recorrido del arreglo utilizando indices
    printf("\n6. Recorrido con indices:\n");

    for (int i = 0; i < 3; i++) {
        printf("%d - %s - %.2f\n",
               students[i].id,
               students[i].name,
               students[i].grade);
    }

    // 9. Recorrido del arreglo utilizando un puntero
    printf("\n7. Recorrido con punteros:\n");

    Student *p = students;

    for (int i = 0; i < 3; i++) {
        printf("%d - %s - %.2f\n",
               (p + i)->id,
               (p + i)->name,
               (p + i)->grade);
    }

    // 10. Recorrido utilizando un puntero que avanza
    printf("\n8. Recorrido con un puntero que avanza:\n");

    for (Student *p = students; p < students + 3; p++) {
        printf("%d - %s - %.2f\n",
               p->id,
               p->name,
               p->grade);
    }

    return 0;
}
