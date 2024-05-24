#include "MeasureArray.h"
#include "Measurement.h"
#include "SortingArray.h"
#include "InputOutputArray.h"

//функція, яка заповнює багатовимірний масив впорядковано, виконує сортування вибором та повертає час сортування

float Array_Selection_Sort_Measurement_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Orderly();
        Res[i] = Array_Selection_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив не впорядковано, виконує сортування вибором та повертає час сортування

float Array_Selection_Sort_Measurement_Disorderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Disorderly();
        Res[i] = Array_Selection_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив обернено-впорядковано, виконує сортування вибором та повертає час сортування

float Array_Selection_Sort_Measurement_Inverted_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Inverted_Orderly();
        Res[i] = Array_Selection_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив впорядковано, виконує сортування вставкою-обміном та повертає час сортування

float Array_Insertion_Exchange_Sort_Measurement_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Orderly();
        Res[i] = Array_Insertion_Exchange_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив не впорядковано, виконує сортування вставкою-обміном та повертає час сортування

float Array_Insertion_Exchange_Sort_Measurement_Disorderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Disorderly();
        Res[i] = Array_Insertion_Exchange_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив обернено-впорядковано, виконує сортування вставкою-обміном та повертає час сортування

float Array_Insertion_Exchange_Sort_Measurement_Inverted_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Inverted_Orderly();
        Res[i] = Array_Insertion_Exchange_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив впорядковано, виконує сортування Шелла та повертає час сортування

float Array_Shell_Sort_Measurement_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Orderly();
        Res[i] = Array_Shell_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив не впорядковано, виконує сортування Шелла та повертає час сортування

float Array_Shell_Sort_Measurement_Disorderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Disorderly();
        Res[i] = Array_Shell_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}

//функція, яка заповнює багатовимірний масив обернено-впорядковано, виконує сортування Шелла та повертає час сортування

float Array_Shell_Sort_Measurement_Inverted_Orderly() {
    float sorting_time;
    for (int i = 0; i < measurements_number; i++) {
        Input_Array_Inverted_Orderly();
        Res[i] = Array_Shell_Sort();
    }
    sorting_time = Measurement_Processing();
    return sorting_time;
}