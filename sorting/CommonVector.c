#include "CommonVector.h"
#include <stdlib.h>
#include <stdio.h>

//створення динамічного вектора

void Create_Vector() {
    Vector = (int *) malloc(N * sizeof(int));
}

//звільнення динамічного вектора

void Free_Vector() {
    free(Vector);
}
