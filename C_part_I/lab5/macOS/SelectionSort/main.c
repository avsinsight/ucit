/**
 * Аветисян Арташес Робертович
 * Лабораторная работа №5 Вариант 6.
 * Задача:
 * Сортировка выбором. Выбирается минимальный элемент в массиве и запомина-ется.
 * Затем удаляется, а все последующие за ним элементы сдвигаются на один влево.
 * Сам элемент заносится на освободившуюся последнюю позицию.
 */

#include <stdio.h>
#include <stdlib.h>

int findMinimumPos(int* a, int end);
void printArray(int* array, int size, char* label);
int* selectionSort(int* array, int size);


int main(int argc, char** argv) {

    int array[] = {5,3,9,2,6,3,8,3,0,2,6,2,8,2,4,5,6,2,3,4,3,42,1,23,5,67,78,8,9,0,65,1,25,8,8,43,3,876,543,1,23,4567,8,87,654,32};
    int size = sizeof(array)/sizeof(array[0]);

    printArray(array, size, "INITIAL ARRAY");

    int* sortedArray = selectionSort(array, size);

    printArray(sortedArray, size, "SORTED ARRAY");

    return (EXIT_SUCCESS);
}

int findMinimumPos(int* a, int end){

    int pos = 0;
    int minimum = a[0];

    for (int i = 1; i < end; i++){
        if (i != end ){
            if (minimum > a[i]){
                pos = i;
                minimum = a[i];
            }
        }
    }

    return pos;
}

void printArray(int* array, int size, char* label)
{

    printf("%s\n", label);
    for (int i = 0; i < size; i++)
    {

        printf("%d ", array[i]);
    }
    printf("\n");

}

int* selectionSort(int* array, int size){

    for (int a = 0; a < size; a++){

        int minPositionIndex = findMinimumPos(array, size - a);
        int shiftedToEndOfArrayElement = array[minPositionIndex];

        for (int i = 0; i < size; i++){
            if (i >= minPositionIndex){

                if (i == size - 1){
                    array[i] = shiftedToEndOfArrayElement;
                } else {
                    array[i] = array[i+1];
                }

            } else{
                array[i] = array[i];
            }
        }
    }

    return array;
}