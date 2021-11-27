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



int main(int arhc, char **argv){
    static int *numero;
    printf("Iniciamos el programa\n\n ");
    FILE *fichero;
    numero = mmap(NULL, sizeof *numero, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0); //variable en memoria compartida
    *numero = 1;
    sem_t *semaforo = mmap(NULL, sizeof(*semaforo), PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0); //semaforo en memoria compartida
    srand(time(NULL));
    float average = 0;
    int array[10], numeros;


    fichero = fopen("resultado.txt","w");
    pid_t pid = fork();

    if(pid == 0){//Inicio del proceso hijo
        
        for(int n = 0; n < 10; n++){
            if(fichero == NULL){
                printf("error de fichero");
                exit(1);
            }
           
            
            if(sem_init(semaforo,1,0) < 0){
                perror("semaforo iniciado");
                exit(EXIT_FAILURE);
            }
            sleep(1);
            if(sem_wait(semaforo) < 0){ //El hijo espera y inicio de semaforo
                perror("semaforo esperando");
            } 
            printf("hijo: leyendo %d\n",*numero);
            array[n] = *numero;
        }
        if(sem_destroy(semaforo) < 0){
            perror("Error de destruccion de semaforo");
            exit(EXIT_FAILURE);
        }
        if(munmap(semaforo, sizeof(semaforo)) < 0){
            perror("Error de munmap");
            exit(EXIT_FAILURE);
        }

        for(int n = 0; n < 9; n++){
            fprintf(fichero,"%d,",array[n]);
            average += array[n];
        }
        average += array[9];
        average = average/10;
        fprintf(fichero,"%d Promedio: %.1f",array[9],average);
 
        fclose(fichero);
        printf("Fin del Programa, escribiendo numeros y promedio\n\n");
    }

    else if(pid > 0){//Proceso del padre
    
        for(int n = 0; n < 10; n++){
            sleep(2);
            *numero = rand() % (10 + 1 - 1) + 1;
            printf("padre: escribiendo %d\n",*numero);
            if(sem_post(semaforo) < 0){ //Padre desbloquea el semaforo,sem_post
                perror("sem_post");
            }
        }
        sleep(2);
        fichero = fopen("resultado.txt","r");
        if(fichero){
            while((numeros = getc(fichero)) != EOF)//EOF ( END OF FILE )
                putchar(numeros);
            printf("\n");
            fclose(fichero);
        }
    }

    else{
    printf("fork() ERROR \n");
    return 1;
   }
}