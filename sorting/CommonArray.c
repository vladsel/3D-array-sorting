#include "CommonArray.h"
#include <stdlib.h>
#include <stdio.h>

//створення динаміного багатовимірного масиву

void Create_Array() {
    Array = (int ***) malloc(p * sizeof(int **));
    for (int k = 0; k < p; k++) {
        Array[k] = (int **) malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++) Array[k][i] = (int *) malloc(n * sizeof(int));
    }
}

//звільнення динамічного багатовимірного масиву

void Free_Array() {
    for (int k = 0; k < p; k++) {
        for (int i = 0; i < m; i++)
            free(Array[k][i]);
        free(Array[k]);
    }
    free(Array);
}
