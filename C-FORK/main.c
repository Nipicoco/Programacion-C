#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

int main(int arhc, char **argv)
{
    static int *numero;                                                                                           // shared memory variable
    printf("Starting program\n\n ");                                                                              // print starting program
    FILE *file1;                                                                                                  // file pointer
    numero = mmap(NULL, sizeof *numero, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);               // number is in shared memory using mmap function which is a system call
    *numero = 1;                                                                                                  // ass
    sem_t *semaphore = mmap(NULL, sizeof(*semaphore), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0); // use a semaphore to synchronize the processes
    srand(time(NULL));                                                                                            // random number generator
    float average = 0;                                                                                            // average variable
    int array[10], numeros;                                                                                       // array of 10 elements

    file1 = fopen("result.txt", "w"); // open file
    pid_t pid = fork();               // fork process

    if (pid == 0) // pid 0 is the child process
    {

        for (int n = 0; n < 10; n++) // for loop to write 10 numbers
        {
            if (file1 == NULL) // if file is null
            {
                printf("file error"); // print error
                exit(1);              // exit
            }

            if (sem_init(semaphore, 1, 0) < 0) // initialize semaphore
            {
                perror("semaphore started"); // print
                exit(EXIT_FAILURE);          // exit
            }
            sleep(1); // sleep 1 second
            if (sem_wait(semaphore) < 0)
            { // pid 0 is the child process that waits for the semaphore
                perror("semaphore waiting");
            }
            printf("PID 0 SON: Reading %d\n", *numero);
            array[n] = *numero;
        }
        if (sem_destroy(semaphore) < 0)
        {
            perror("Semaphore destruction error");
            exit(EXIT_FAILURE);
        }
        if (munmap(semaphore, sizeof(semaphore)) < 0)
        {
            perror("Munmap error");
            exit(EXIT_FAILURE);
        }

        for (int n = 0; n < 9; n++)
        {
            fprintf(file1, "%d,", array[n]);
            average += array[n];
        }
        average += array[9];
        average = average / 10;
        fprintf(file1, "%d Average: %.1f", array[9], average);

        fclose(file1);
        printf("program ending, writing data to txt\n\n");
    }

    else if (pid > 0)
    { // pid > 0 is the parent process

        for (int n = 0; n < 10; n++) // for loop to write 10 numbers
        {
            sleep(2);
            *numero = rand() % (10 + 1 - 1) + 1;
            printf("Parent process: writing %d\n", *numero);
            if (sem_post(semaphore) < 0)
            {                       // PID > 0 is the parent process that releases the semaphore
                perror("sem_post"); // print error
            }
        }
        sleep(2);                         // sleep 2 seconds
        file1 = fopen("result.txt", "r"); // open file
        if (file1)                        // if file is not null
        {
            while ((numeros = getc(file1)) != EOF) // EOF ( END OF FILE ) is a macro that expands to an integer constant expression with a value of -1
                putchar(numeros);                  // print the numbers
            printf("\n");                          // print new line
            fclose(file1);                         // close file
        }
    }

    else
    {                              // if pid is not 0 or > 0
        printf("fork() ERROR \n"); // print error
        return 1;                  // return 1
    }
}