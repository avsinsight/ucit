#include <stdio.h>

/**
 * Изучение операторов, управляющих структур, работа с целочисленными массивами в Си
 * Лабораторная №2: вариант 13. Исполнил: Аветисян Арташес Робертович
 * 13. Найти в массиве наибольшее число подряд идущих одинаковых элементов
 * (например {1,5,3,6,6,6,6,6,3,4,4,5,5,5} = 5).
 */

void showArray(int* array, int size);
int getSameValueBiggestCount (int* array, int size);

int main() {

    int rawData[] = {1,5,3,6,6,6,6,6,3,4,4,5,5,5};
    int rawDataArraySize = sizeof rawData / sizeof rawData[0];

    showArray(rawData, rawDataArraySize);

    printf("RESULT: biggestCount =  %d\n", getSameValueBiggestCount(rawData, rawDataArraySize));

    return 0;
}

void showArray(int* array, int size){

    printf("CURRENT ARRAY ELEMENTS:\n");

    for (int a = 0; a < size; a++ ){
        if (a != size - 1) {
            printf("%d,", array[a]);
        } else {
            printf("%d", array[a]);
        }
    }
}

int getSameValueBiggestCount (int* array, int size){

    printf("\nPROCESSING...\n");

    int biggestCount = 0;
    int sameValueCountHolder = 0;

    for (int i = 0; i < size; i++ ) {
        if (array[i] == array[i+1]){
            sameValueCountHolder++;
        } else {
            sameValueCountHolder++;
            if (sameValueCountHolder > biggestCount){
                biggestCount = sameValueCountHolder;
            }
            sameValueCountHolder = 0;
        }
    }

    return biggestCount;
}
