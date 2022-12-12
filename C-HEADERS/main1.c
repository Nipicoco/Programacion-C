#include <stdio.h>
#include "main2.h"
// we include the header file with the functions
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

    /*llamando numberAv()*/
    prom = numberAv(a, b);

    printf("Sum: %d \nAverage: %f\n", suma, prom);

    return 0;
}
