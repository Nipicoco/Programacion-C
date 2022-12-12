// Created: 2019-10-10 10:00:00
// using C-HEADERS\main.c we will create a header file with the functions and include it in the main.c file, later we will compile the main.c file and the header file will be included in the compilation process
int sumatoria(int x, int y)
{
    int suma;
    suma = x + y;
    return suma;
}

/*
 * numberAv() - calc the average of two numbers
 * @x: first number
 * @y: second number
 * return: average of two numbers
 */

float numberAv(int x, int y)
{
    int suma;
    float prom;

    suma = x + y;
    prom = suma / 2;
    return prom;
}
