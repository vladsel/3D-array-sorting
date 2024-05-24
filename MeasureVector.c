#include "MeasureVector.h"
#include "Measurement.h"
#include "SortingVector.h"
#include "InputOutputVector.h"

//функція, яка заповнює вектор впорядковано, виконує сортування вибором та повертає час сортування

float Vector_Selection_Sort_Measurement_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Orderly();
        Res[i] = Vector_Selection_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор не впорядковано, виконує сортування вибором та повертає час сортування

float Vector_Selection_Sort_Measurement_Disorderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Disorderly();
        Res[i] = Vector_Selection_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор обернено-впорядковано, виконує сортування вибором та повертає час сортування

float Vector_Selection_Sort_Measurement_Inverted_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Inverted_Orderly();
        Res[i] = Vector_Selection_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор впорядковано, виконує сортування вставкою-обміном та повертає час сортування

float Vector_Insertion_Exchange_Sort_Measurement_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Orderly();
        Res[i] = Vector_Insertion_Exchange_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор не впорядковано, виконує сортування вставкою-обміном та повертає час сортування

float Vector_Insertion_Exchange_Sort_Measurement_Disorderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Disorderly();
        Res[i] = Vector_Insertion_Exchange_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор обернено-впорядковано, виконує сортування вставкою-обміном та повертає час сортування

float Vector_Insertion_Exchange_Sort_Measurement_Inverted_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Inverted_Orderly();
        Res[i] = Vector_Insertion_Exchange_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор впорядковано, виконує сортування Шелла та повертає час сортування

float Vector_Shell_Sort_Measurement_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Orderly();
        Res[i] = Vector_Shell_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор не впорядковано, виконує сортування Шелла та повертає час сортування

float Vector_Shell_Sort_Measurement_Disorderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Disorderly();
        Res[i] = Vector_Shell_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює вектор обернено-впорядковано, виконує сортування Шелла та повертає час сортування

float Vector_Shell_Sort_Measurement_Inverted_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Vector_Inverted_Orderly();
        Res[i] = Vector_Shell_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}