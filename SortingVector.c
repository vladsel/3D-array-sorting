#include "SortingVector.h"
#include "CommonVector.h"
#include <math.h>

//сортування вектора вибором

clock_t Vector_Selection_Sort() {
    int L, R, imin, imax, temp;
    clock_t time_start, time_stop;

    time_start = clock();

    L = 0;
    R = N - 1;
    while (L < R) {
        imin = L;
        imax = L;
        for (int i = L + 1; i < R + 1; i++)
            if (Vector[i] < Vector[imin])
                imin = i;
            else if (Vector[i] > Vector[imax])
                imax = i;
        if (imin != L) {
            temp = Vector[imin];
            Vector[imin] = Vector[L];
            Vector[L] = temp;
        }
        if (imax != R)
            if (imax == L) {
                temp = Vector[imin];
                Vector[imin] = Vector[R];
                Vector[R] = temp;
            } else {
                temp = Vector[imax];
                Vector[imax] = Vector[R];
                Vector[R] = temp;
            }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

//сортування вектора вставкою-обміном

clock_t Vector_Insertion_Exchange_Sort() {
    int j, temp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int i = 1; i < N; i++) {
        j = i;
        while (j > 0 && Vector[j] < Vector[j - 1]) {
            temp = Vector[j];
            Vector[j] = Vector[j - 1];
            Vector[j - 1] = temp;
            j = j - 1;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

//сортування Шелла вектора

clock_t Vector_Shell_Sort() {
    int Elem, t, j, k;
    int Stages[(N - 1) / 4 + 1];
    clock_t time_start, time_stop;

    time_start = clock();

    if (N < 4)
        t = 1;
    else
        t = (int) log2f((float) N) - 1;
    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--)
        Stages[i] = 2 * Stages[i + 1] + 1;
    for (int q = 0; q < t; q++) {
        k = Stages[q];
        for (int i = k; i < N; i++) {
            Elem = Vector[i];
            j = i;
            while (j >= k && Elem < Vector[j - k]) {
                Vector[j] = Vector[j - k];
                j = j - k;
            }
            Vector[j] = Elem;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
