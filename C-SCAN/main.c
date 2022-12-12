#include <stdio.h>
int main()
{
    int num1, num2, flag_var, i, j;

    /* Enter a range of numbers
     * Ej, 1 to 100 or 100 a 1000.
     */
    printf("Enter number range:");
    // save the scanned variables
    scanf("%d %d", &num1, &num2);

    // Display the prime numbers
    printf("Los numeros primos entre %d y %d son:\n", num1, num2); // \n is a new line
    for (i = num1 + 1; i < num2; ++i)                              // i starts at num1+1 and ends at num2
    {                                                              // i is the number to be checked
        flag_var = 0;                                              // flag_var is a flag variable
        for (j = 2; j <= i / 2; ++j)                               // j is the number to be checked against i
        {                                                          // j starts at 2 and ends at i/2
            if (i % j == 0)                                        // if i is divisible by j
            {                                                      // then i is not a prime number
                flag_var = 1;                                      // flag_var is set to 1
                break;                                             // break the loop
            }
        }                      // end of j loop
        if (flag_var == 0)     // if flag_var is 0
            printf("%d\n", i); // then i is a prime number
    }                          // end of i loop
    return 0;                  // end of program