#include <stdio.h>
int main()
{
    int num1, num2, num3;
    int *p1, *p2, *p3;

    // Input usuario
    printf("Enter First number: ");
    scanf("%d", &num1);
    printf("Enter Second number: ");
    scanf("%d", &num2);
    printf("Enter Third number: ");
    scanf("%d", &num3);

    // Assign pointers to the numbers
    p1 = &num1;        // p1 points to num1
    p2 = &num2;        // p2 points to num2
    p3 = &num3;        // p3 points to num3
    if (*p1 > *p2)     // if num1 is greater than num2
    {                  // then check if num1 is greater than num3
        if (*p1 > *p3) // if num1 is greater than num3
        {
            printf("%d is the biggest number", *p1); // then num1 is the biggest number
        }
        else
        { // if num3 is greater than num1
            printf("%d is the biggest number", *p3);
        }
    }
    else
    {
        if (*p2 > *p3)
        {
            printf("%d is the biggest number", *p2); // then num2 is the biggest number
        }
        else
        {
            printf("%d is the biggest number", *p3);
        } // if num3 is greater than num2
    }
    return 0;
}