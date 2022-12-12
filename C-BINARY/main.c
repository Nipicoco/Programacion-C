#include <stdio.h>

int sumaBin(int a, int b)
{
    int c; // variable to store carry
    while (b != 0)
    {
        // find carry and shift it left by 1 so that adding it to a gives the required sum
        c = (a & b) << 1;
        // find sum of bits of a and b
        a = a ^ b;
        b = c;
    }
    return a; // return sum
}

// binary subtraction
int restaBin(int a, int b)
{
    int carry;
    // get the 2's complement of b and add it to a, carry will be 0
    b = sumaBin(~b, 1);

    while (b != 0)
    {
        // while b is not 0, find carry and shift it left by 1 so that adding it to a gives the required sum
        carry = (a & b) << 1;
        // find the sum of bits of a and b once again
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{
    int numero1, numero2, sumabinaria, restabinaria;

    printf("Enter first value: "); // deprecated but works
    scanf("%d", &numero1);

    printf("Enter second value: ");
    scanf("%d", &numero2);

    sumabinaria = sumaBin(numero1, numero2);
    restabinaria = restaBin(numero1, numero2);

    printf("Suma Binaria: %d\n", sumabinaria);
    printf("Resta Binaria: %d\n", restabinaria);

    return 0; // return 0 to exit program
}
