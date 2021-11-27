#include <stdio.h>
int main()
{
    int num1, num2, flag_var, i, j;

    /* Ingresar numeros desde un rango
     * Ej, 1 a 100 y o 100 a 1000.
     */
    printf("Ingresar rango de numeros enteros:");
    //Guarda las variables en scanf
    scanf("%d %d", &num1, &num2);

    //Dsiplay de los numeros primos
    printf("Los numeros primos entre %d y %d son:\n", num1, num2);
    for(i=num1+1; i<num2; ++i)
    {
        flag_var=0;
        for(j=2; j<=i/2; ++j)
        {
            if(i%j==0)
            {
                flag_var=1;
                break;
            }
        }
        if(flag_var==0)
            printf("%d\n",i);
    }
    return 0;