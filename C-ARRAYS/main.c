#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* variable declaration. */
    int *pointers;
    int arraylimit;
    int i;
    int sumtotal;

    printf("Enter the array limit: ");
    scanf("%d", &arraylimit);

    // declare memory malloc
    pointers = (int *)malloc(arraylimit * sizeof(int));

    // read array elements
    for (i = 0; i < arraylimit; i++)
    {
        printf("Enter element %02d: ", i + 1);
        scanf("%d", (pointers + i));
    }

    // Print the array elements
    printf("\nThe values inputted where:\n");
    for (i = 0; i < arraylimit; i++)
    {
        printf("%d\n", *(pointers + i));
    }

    // calculate the total sum
    sumtotal = 0; // assign 0 to sumtotal to avoid garbage value
    for (i = 0; i < arraylimit; i++)
    {
        sumtotal += *(pointers + i);
    }
    printf("Sum of the array: %d\n", sumtotal);

    // free memory pointer
    free(pointers);

    return 0;
}
