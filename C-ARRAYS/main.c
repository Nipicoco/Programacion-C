#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pointers; //declarando pointer entero
    int limite; //guardando limite de array
    int i; //contador loop
    int suma; //guardar la suma de todos los elementos

    printf("Ingresar limite de array: ");
    scanf("%d", &limite);

    //declarar malloc de memoria
    pointers = (int*)malloc(limite * sizeof(int));

    //leer array de elementos
    for (i = 0; i < limite; i++) {
        printf("Ingresar elemento %02d: ", i + 1);
        scanf("%d", (pointers + i));
    }

    //printear array de elementos
    printf("\nLos elementos ingresados son:\n");
    for (i = 0; i < limite; i++) {
        printf("%d\n", *(pointers + i));
    }

    //calcular la suma del array
    suma = 0; //asignar 0 para evitar numeros basura
    for (i = 0; i < limite; i++) {
        suma += *(pointers + i);
    }
    printf("La suma del array: %d\n", suma);

    //memoria sin usar
    free(pointers); //liberar memoria usada.

    return 0;
}
