#include <stdio.h>
#include "main2.h"

int main()
{
    int a, b;
    int suma;
    float prom;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    /*llamando sumatoria()*/
    suma = sumatoria(a, b);

    /*llamando promNumeros()*/
    prom = promNumeros(a, b);

    printf("Suma: %d \nPromedio: %f\n", suma, prom);

    return 0;
}
