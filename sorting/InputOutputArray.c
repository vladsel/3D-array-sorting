#include "InputOutputArray.h"
#include "CommonArray.h"
#include "Error.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

//заповення багатовимірного масиву впорядковано

void Input_Array_Orderly() {
    long int number = 0;
    for (int k = 0; k < p; k++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                Array[k][i][j] = number++;
}

//заповення багатовимірного масиву не впорядковано

void Input_Array_Disorderly() {
    srand(time(NULL));
    for (int k = 0; k < p; k++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                Array[k][i][j] = rand() % (p * m * n);
}
//заповення багатовимірного масиву обернено-впорядковано

void Input_Array_Inverted_Orderly() {
    long int number = p * m * n - 1;
    for (int k = 0; k < p; k++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                Array[k][i][j] = number--;
}

//вивід багатовимірного масиву

void Output_Array() {
    for (int k = 0; k < p; k++) {
        printf("\n");
        for (int i = 0; i < m; i++) {
            printf("[");
            for (int j = 0; j < n; j++)
                printf("%6d", Array[k][i][j]);
            printf("]\n");
        }
    }
    printf("\n\n\n");
}

//заповннення користувачем розмірів багатовимірного масиву

void Input_Array_Size() {
    printf("Input array sizes:\n\np = ");
    scanf("%d", &p);
    while (p < 0 || p > 999999999) {
        Error();
        printf("p = ");
        scanf("%d", &p);
    }
    printf("\nm = ");
    scanf("%d", &m);
    while (m < 0 || m > 999999999) {
        Error();
        printf("m = ");
        scanf("%d", &m);
    }
    printf("\nn = ");
    scanf("%d", &n);
    printf("\n");
    while (n < 0 || n > 999999999) {
        Error();
        printf("n = ");
        scanf("%d", &n);
    }
    if (p == 0 || m == 0 || n == 0) {
        printf("\n\nerror, emergency exit from the program");
        sleep(3);
        exit(1);
    }
}