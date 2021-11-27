#include <stdio.h>

// funcion para suma binaria
int sumaBin(int a, int b)
{
    int c; //carry
    while (b != 0) {
        //encontrar carry y mandarlo a la izquierda
        c = (a & b) << 1;
        //encontrar la suma
        a = a ^ b;
        b = c;
    }
    return a;
}

// funcion para resta binaria
int restaBin(int a, int b)
{
    int carry;
    //tomar 2 complementos 
    b = sumaBin(~b, 1);

    while (b != 0) {
        //encontrar carry y mandarlo a la izquierda
        carry = (a & b) << 1;
        //encontrar la suma
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{
    int numero1, numero2, sumabinaria, restabinaria;

    printf("Ingresar primer valor entero: ");
    scanf("%d", &numero1);

    printf("Ingresar segundo valor entero: ");
    scanf("%d", &numero2);

    sumabinaria = sumaBin(numero1, numero2);
    restabinaria = restaBin(numero1, numero2);

    printf("Suma Binaria: %d\n", sumabinaria);
    printf("Resta Binaria: %d\n", restabinaria);

    return 0;
}
