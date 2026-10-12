#include <stdio.h>
#include <stdlib.h>

void insertar(int arr[], int *tam, int pos, int valor);
int buscar(int arr[], int tam, int clave);
int eliminar(int arr[], int *tam, int valor);
void recorrido(int arr[], int tam) ;
void menu();

int main()
{
    int arr[10] = {10, 20, 40, 50};
    int tam = 4;
    int opc = 0;
    int valor, pos;
    while(opc!=5){
        menu();
        scanf("%d",&opc);
        switch(opc){
            case 1:
				system("clear");
                recorrido(arr,tam);
				system("read -p 'Presiona Enter para continuar...'");
            break;
            case 2:
				system("clear");
                printf("Introduce el valor a insertar: ");
                scanf("%d",&valor);
                printf("Introduce la posicion donde se insertara: ");
                scanf("%d",&pos);
                insertar(arr,&tam,pos,valor);
				system("read -p 'Presiona Enter para continuar...'");
            break;
            case 3:
				system("clear");
                printf("Introduce el valor a eliminar: ");
                scanf("%d",&valor);
				pos = eliminar(arr,&tam,valor);
				system("read -p 'Presiona Enter para continuar...'");
            break;
            case 4:
				system("clear");
                printf("Introduce el valor a buscar: ");
                scanf("%d",&valor);
				pos = buscar(arr,tam,valor);
				if(pos){
                	printf("El valor %d esta en la posicion:%d.",valor,pos);
				}else{
                	printf("El valor %d no esta.",valor);
				}
				system("read -p 'Presiona Enter para continuar...'");
            break;
            case 5:
                printf("\nBye ... :D\n");
            break;
        }
    }
    return 0;
}
