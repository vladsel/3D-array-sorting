#include "Menu.h"
#include "CommonArray.h"
#include "CommonVector.h"
#include "InputOutputArray.h"
#include "InputOutputVector.h"
#include "MeasureArray.h"
#include "MeasureVector.h"
#include "SortingArray.h"
#include "SortingVector.h"
#include "Error.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

//переміщення по консолі

void Coord(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//створення рамки

void Frame(int x1, int y1, int x2, int y2, int print) {
    int i;
    Coord(x1, y1);
    printf("\311");
    for (i = (x1 + 1); i <= (x2 - 1); i++) {
        printf("\315");
        if (print == 1)
            usleep(3000);
    }
    printf("\273");
    for (i = (y1 + 1); i <= (y2 - 1); i++) {
        Coord(x1, i);
        printf("\272");
        if (print == 1)
            usleep(3000);
        Coord(x2, i);
        printf("\272");
        if (print == 1)
            usleep(3000);
    }
    Coord(x1, y2);
    printf("\310");
    for (i = (x1 + 1); i <= (x2 - 1); i++) {
        printf("\315");
        if (print == 1)
            usleep(3000);
    }
    printf("\274");
}

//вивід рамки та всіх даних на консоль

void Info() {
    Close();
    Frame(1, 1, 110, 25, 1);
    Coord(50, 8);
    printf("Course Work\n");
    Coord(50, 10);
    printf("Subject SDA\n");
    Coord(50, 12);
    printf("Variant 85\n");
    Coord(45, 14);
    printf("by Seletkov Vladislav\n");
    Coord(52, 16);
    printf("KV - 91");
    Coord(51, 21);
    printf("Kiev 2020\n");
}

//створення таблички з вимірами часу алгоритмів у пакетному режимі

void Out_Table(float ordered, float random, float back_ordered, int flag) {
    if (flag == 1) {
        printf("\n\t_________________________________________________________________________________________________\n");
        printf("\t|\t\t\t|\t Ordered \t|\t  Random \t|\tBackOrdered \t|\n");
        printf("\t|-----------------------|-----------------------|-----------------------|-----------------------|\n");
        printf("\t|\tSelection 8\t|\t%7.2f \t|\t%7.2f \t|\t%7.2f \t|\n", ordered, random, back_ordered);
        printf("\t|-----------------------|-----------------------|-----------------------|-----------------------|\n");
    } else if (flag == 2) {
        printf("\t|   Insertion Exchange\t|\t%7.2f \t|\t%7.2f \t|\t%7.2f \t|\n", ordered, random, back_ordered);
        printf("\t|-----------------------|-----------------------|-----------------------|-----------------------|\n");
    } else if (flag == 3) {
        printf("\t|\tShell 1\t\t|\t%7.2f \t|\t%7.2f \t|\t%7.2f \t|\n", ordered, random, back_ordered);
        printf("\t|_______________________|_______________________|_______________________|_______________________|\n");
        printf("\n\n");
    }
}

//очищення екрану

void Close() {
    system("cls");
}

//створення заставки

void Screen() {
    Info();
    char choice;
    printf("\n\n\n\nSelect 1 to continue or select 0 to exit: ");
    choice = getch();
    while (1) {
        if (choice != '0' && choice != '1') {
            Error();
            choice = getch();
        } else if (choice == '1')
            while (1) { //зациклення меню, що робить неможливим повернення до заставки
                Close();
                General_Menu();
            }
        else exit(0);
    }
}

//створення основного меню

void General_Menu() {
    printf("\n\n\n\n\n");
    char Points[5][60] = {
            "1. Sorting multidimensional array algorithms in batch mode.",
            "2. Sorting vector algorithms in batch mode.",
            "3. Multidimensional array sorting algorithm test.",
            "4. Vector sorting algorithm test.",
            "5. Exit."
    };
    for (int i = 0; i < 5; i++)
        printf("\t\t\t%s\n", Points[i]);
    printf("\n\t\t\tPlease, choose an action");
    Frame(1, 1, 110, 25, 0);
    float ordered, random, back_ordered;
    int choice, flag;
    char temp;
    temp = getch();
    while (1) {
        if (temp != '1' && temp != '2' && temp != '3' && temp != '4' && temp != '5') {
            Error();
            temp = getch();
        } else {
            choice = (int) temp - 48;
            break;
        }
    }

    //змінна choice, через яку далі здійснюється
    //1 - перехід до сортування багатовимірного масиву в пакетному режимі
    //2 - перехід до сортування вектора в пакетному режимі
    //3 - тестове сортування багатовимірного масиву з вибором заповнення та вибором алгоритма з виводом на екран
    //4 - тестове сортування вектора з вибором заповнення та вибором алгоритма з виводом на екран
    //5 - вихід з програми

    if (choice == 1) {
        Close();
        flag = 1;
        Input_Array_Size();
        Close();
        Create_Array();
        ordered = Array_Selection_Sort_Measurement_Orderly();
        random = Array_Selection_Sort_Measurement_Disorderly();
        back_ordered = Array_Selection_Sort_Measurement_Inverted_Orderly();
        Out_Table(ordered, random, back_ordered, flag);
        flag = 2;
        ordered = Array_Insertion_Exchange_Sort_Measurement_Orderly();
        random = Array_Insertion_Exchange_Sort_Measurement_Disorderly();
        back_ordered = Array_Insertion_Exchange_Sort_Measurement_Inverted_Orderly();
        Out_Table(ordered, random, back_ordered, flag);
        flag = 3;
        ordered = Array_Shell_Sort_Measurement_Orderly();
        random = Array_Shell_Sort_Measurement_Disorderly();
        back_ordered = Array_Shell_Sort_Measurement_Inverted_Orderly();
        Free_Array();
        Out_Table(ordered, random, back_ordered, flag);
        system("pause");
        Close();
    } else if (choice == 2) {
        Close();
        flag = 1;
        Input_Vector_Size();
        Close();
        Create_Vector();
        ordered = Vector_Selection_Sort_Measurement_Orderly();
        random = Vector_Selection_Sort_Measurement_Disorderly();
        back_ordered = Vector_Selection_Sort_Measurement_Inverted_Orderly();
        Out_Table(ordered, random, back_ordered, flag);
        flag = 2;
        ordered = Vector_Insertion_Exchange_Sort_Measurement_Orderly();
        random = Vector_Insertion_Exchange_Sort_Measurement_Disorderly();
        back_ordered = Vector_Insertion_Exchange_Sort_Measurement_Inverted_Orderly();
        Out_Table(ordered, random, back_ordered, flag);
        flag = 3;
        ordered = Vector_Shell_Sort_Measurement_Orderly();
        random = Vector_Shell_Sort_Measurement_Disorderly();
        back_ordered = Vector_Shell_Sort_Measurement_Inverted_Orderly();
        Free_Vector();
        Out_Table(ordered, random, back_ordered, flag);
        system("pause");
        Close();
    } else if (choice == 3 || choice == 4) {
        Close();
        while (Sorting_Algorithm_Menu(choice)); //передача вибору тестовго сортуання 3 - багатовимірного масиву або 4 - вектора до наступної функції
    } else if (choice == 5)
        exit(0);
    Close();
}

//вибір алгоритма тестового сортування
//змінна result зберігає значення того, що було вибрано користувачем, багатовимірний масив чи вектор

int Sorting_Algorithm_Menu(int result) {
    printf("\n\n\n\n\n");
    char Points[4][41] = {
            "1. Selection sorting algorithm.",
            "2. Insertion exchange sorting algorithm.",
            "3. Shell sorting algorithm.",
            "4. Go back to menu."
    };
    for (int i = 0; i < 4; i++)
        printf("\t\t\t\t%s\n", Points[i]);
    printf("\n\t\t\t\tPlease, choose an action");
    Frame(1, 1, 110, 25, 0);
    int choice_alg;
    char temp;
    temp = getch();
    while (1) {
        if (temp != '1' && temp != '2' && temp != '3' && temp != '4') {
            Error();
            temp = getch();
        } else if (temp == '4')
            return 0;
        else {
            choice_alg = (int) temp - 48;
            break;
        }
    }
    Close();
    while (Input_Menu(result, choice_alg)); //передача, вибраного користувачем, алгоритму сортування та передача змінної result
}                                           //яка зберігає значення того, що було вибрано користувачем, багатовимірний масив чи вектор

//вибір заповнення масиву для тестового сортування

int Input_Menu(int result, int choice_alg) {
    printf("\n\n\n\n\n");
    char Points[4][27] = {
            "1. Input orderly.",
            "2. Input disorderly.",
            "3. Input inverted orderly.",
            "4. Go back to menu."
    };
    for (int i = 0; i < 4; i++)
        printf("\t\t\t\t%s\n", Points[i]);
    printf("\n\t\t\t\tPlease, choose an action");
    Frame(1, 1, 110, 25, 0);
    int choice_input;
    char temp;
    temp = getch();
    while (temp != '1' && temp != '2' && temp != '3' && temp != '4') {
        Error();
        temp = getch();
    }
    choice_input = (int) temp - 48; //вибране користувачем заповнення масиву

    //result: 3 - багатовимірний масив, 4 - вектор
    //choice_ald: 1 - сортування вибором, 2 - сортування вставкою-обміном, 3 - сортування Шелла
    //choice_input: 1 - впорядковане заповнення, 2 - не впорядковане заповнення, 3 - обернено-впорядковане заповнення, 4 - повернення до меню

    switch (result) {
        case 3:
            switch (choice_alg) {
                case 1:
                    switch (choice_input) {
                        case 1:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Orderly();
                            printf("Ordered Array: \n\n");
                            Output_Array();
                            Array_Selection_Sort();
                            printf("Selection sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 2:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Disorderly();
                            printf("Disordered Array: \n\n");
                            Output_Array();
                            Array_Selection_Sort();
                            printf("Selection sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 3:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Inverted_Orderly();
                            printf("Inverted orderly Array: \n\n");
                            Output_Array();
                            Array_Selection_Sort();
                            printf("Selection sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 4:
                            Close();
                            return 0;
                    }
                    break;
                case 2:
                    switch (choice_input) {
                        case 1:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Orderly();
                            printf("Ordered Array: \n\n");
                            Output_Array();
                            Array_Insertion_Exchange_Sort();
                            printf("Insertion exchange sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 2:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Disorderly();
                            printf("Disordered Array: \n\n");
                            Output_Array();
                            Array_Insertion_Exchange_Sort();
                            printf("Insertion exchange sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 3:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Inverted_Orderly();
                            printf("Inverted orderly Array: \n\n");
                            Output_Array();
                            Array_Insertion_Exchange_Sort();
                            printf("Insertion exchange sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 4:
                            Close();
                            return 0;
                    }
                    break;
                case 3:
                    switch (choice_input) {
                        case 1:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Orderly();
                            printf("Ordered Array: \n\n");
                            Output_Array();
                            Array_Shell_Sort();
                            printf("Shell sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 2:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Disorderly();
                            printf("Disordered Array: \n\n");
                            Output_Array();
                            Array_Shell_Sort();
                            printf("Shell sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 3:
                            Close();
                            Input_Array_Size();
                            Create_Array();
                            Input_Array_Inverted_Orderly();
                            printf("Inverted orderly Array: \n\n");
                            Output_Array();
                            Array_Shell_Sort();
                            printf("Shell sorted Array: \n\n\n");
                            Output_Array();
                            Free_Array();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 4:
                            Close();
                            return 0;
                    }
                    break;
            }
            break;
        case 4:
            switch (choice_alg) {
                case 1:
                    switch (choice_input) {
                        case 1:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Orderly();
                            printf("Ordered Vector: \n\n");
                            Output_Vector();
                            Vector_Selection_Sort();
                            printf("Selection sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 2:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Disorderly();
                            printf("Disordered Vector: \n\n");
                            Output_Vector();
                            Vector_Selection_Sort();
                            printf("Selection sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 3:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Inverted_Orderly();
                            printf("Inverted orderly Vector: \n\n");
                            Output_Vector();
                            Vector_Selection_Sort();
                            printf("Selection sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 4:
                            Close();
                            return 0;
                    }
                    break;
                case 2:
                    switch (choice_input) {
                        case 1:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Orderly();
                            printf("Ordered Vector: \n\n");
                            Output_Vector();
                            Vector_Insertion_Exchange_Sort();
                            printf("Insertion exchange sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 2:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Disorderly();
                            printf("Disordered Vector: \n\n");
                            Output_Vector();
                            Vector_Insertion_Exchange_Sort();
                            printf("Insertion exchange sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 3:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Inverted_Orderly();
                            printf("Inverted orderly Vector: \n\n");
                            Output_Vector();
                            Vector_Insertion_Exchange_Sort();
                            printf("Insertion exchange sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 4:
                            Close();
                            return 0;
                    }
                    break;
                case 3:
                    switch (choice_input) {
                        case 1:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Orderly();
                            printf("Ordered Vector: \n\n");
                            Output_Vector();
                            Vector_Shell_Sort();
                            printf("Shell sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 2:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Disorderly();
                            printf("Disordered Vector: \n\n");
                            Output_Vector();
                            Vector_Shell_Sort();
                            printf("Shell sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 3:
                            Close();
                            Input_Vector_Size();
                            Create_Vector();
                            Input_Vector_Inverted_Orderly();
                            printf("Inverted orderly Vector: \n\n");
                            Output_Vector();
                            Vector_Shell_Sort();
                            printf("Shell sorted Vector: \n\n\n");
                            Output_Vector();
                            Free_Vector();
                            printf("\n\n");
                            system("pause");
                            Close();
                            break;
                        case 4:
                            Close();
                            return 0;
                    }
                    break;
            }
            break;
    }
    Close();
}
