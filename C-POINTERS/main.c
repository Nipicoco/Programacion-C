#include <stdio.h>
int main()
{
    int num1, num2, num3;
    int *p1, *p2, *p3;

    //Input usuario
    printf("Ingresar Primer Numero: ");
    scanf("%d",&num1);
    printf("Ingresar Segundo Numero: ");
    scanf("%d",&num2);
    printf("Ingresar Tercer Numero: ");
    scanf("%d",&num3);

    //Asignacion de numeros a los ppointers
    p1 = &num1;
    p2 = &num2;
    p3 = &num3;
    if(*p1 > *p2)
    {
	if(*p1 > *p3)
	{
		printf("%d es el numero mas grande", *p1);
	}
	else
	{
		printf("%d es el numero mas grande", *p3);
	}
    }
    else
    {
	if(*p2 > *p3)
	{
		printf("%d es el numero mas grande", *p2);
	}
	else
	{
		printf("%d es el numero mas grande", *p3);
	}
    }
    return 0;
}