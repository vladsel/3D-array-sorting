#include "SortingArray.h"
#include "CommonArray.h"
#include <math.h>

//сортування багатовимірного масиву вибором

clock_t Array_Selection_Sort() {
    int i, j, k, temp, L, R, imin, imax;
    clock_t time_start, time_stop;

    time_start = clock();

    L = 0;
    R = p - 1;
    while (L < R) {
        imin = L;
        imax = L;
        for (k = L + 1; k < R + 1; k++)
            if (Array[k][0][0] < Array[imin][0][0])
                imin = k;
            else if (Array[k][0][0] > Array[imax][0][0])
                imax = k;
        if (imin != L)
            for (i = 0; i < m; i++)
                for (j = 0; j < n; j++) {
                    temp = Array[imin][i][j];
                    Array[imin][i][j] = Array[L][i][j];
                    Array[L][i][j] = temp;
                }
        if (imax != R)
            if (imax == L)
                for (i = 0; i < m; i++)
                    for (j = 0; j < n; j++) {
                        temp = Array[imin][i][j];
                        Array[imin][i][j] = Array[R][i][j];
                        Array[R][i][j] = temp;
                    }
            else
                for (i = 0; i < m; i++)
                    for (j = 0; j < n; j++) {
                        temp = Array[imax][i][j];
                        Array[imax][i][j] = Array[R][i][j];
                        Array[R][i][j] = temp;
                    }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

//сортування багатовимірного масиву вставкою-обміном

clock_t Array_Insertion_Exchange_Sort() {
    int i, j, k, temp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int r = 1; r < p; r++) {
        k = r;
        while (k > 0 && Array[k][0][0] < Array[k - 1][0][0]) {
            for (i = 0; i < m; i++)
                for (j = 0; j < n; j++) {
                    temp = Array[k][i][j];
                    Array[k][i][j] = Array[k - 1][i][j];
                    Array[k - 1][i][j] = temp;
                }
            k = k - 1;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

//сортування Шелла багатовимірного масиву

clock_t Array_Shell_Sort() {
    int Elem[m][n], Stages[(p - 1) / 4 + 1];
    int t, j, k, r, q;
    clock_t time_start, time_stop;

    time_start = clock();

    if (p < 4)
        t = 1;
    else
        t = (int) log2f((float) p) - 1;
    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--)
        Stages[i] = 2 * Stages[i + 1] + 1;
    for (int g = 0; g < t; g++) {
        k = Stages[g];
        for (int i = k; i < p; i++) {
            for (r = 0; r < m; r++)
                for (q = 0; q < n; q++)
                    Elem[r][q] = Array[i][r][q];
            j = i;
            while (j >= k && Elem[0][0] < Array[j - k][0][0]) {
                for (r = 0; r < m; r++)
                    for (q = 0; q < n; q++)
                        Array[j][r][q] = Array[j - k][r][q];
                j = j - k;
            }
            for (r = 0; r < m; r++)
                for (q = 0; q < n; q++)
                    Array[j][r][q] = Elem[r][q];
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}


