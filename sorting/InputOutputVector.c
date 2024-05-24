#include "InputOutputVector.h"
#include "CommonVector.h"
#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

//заповнення вектора впорядковано

void Input_Vector_Orderly() {
    for (long int i = 0; i < N; i++)
        Vector[i] = i;
}

//заповнення вектора не впорядковано

void Input_Vector_Disorderly() {
    srand(time(NULL));
    for (long int i = 0; i < N; i++)
        Vector[i] = rand() % N;
}

//заповнення вектора обернено-впорядковано

void Input_Vector_Inverted_Orderly() {
    for (long int i = 0; i < N; i++)
        Vector[i] = N - i - 1;
}

// вивід вектора

void Output_Vector() {
    for (long int i = 0; i < N; i++)
        printf("%6d", Vector[i]);
    printf("\n\n\n");
}

//заповнення користувачем розмір вектора

void Input_Vector_Size() {
    printf("Input vector size:\n\nN = ");
    scanf("%ld", &N);
    printf("\n");
    if (N == 0) {
        printf("\n\nerror, emergency exit from the program");
        sleep(3);
        exit(1);
    }
    while (N < 0 || N > 999999999) {
        Error();
        printf("N = ");
        scanf("%ld", &N);
    }
}
