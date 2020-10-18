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

    int rawData[] = {1,5,3,6,6,6,6,4,4,4,4,4,4,4,4,4,4,6,6,5,3,2,3,4,2,4,6,2,4,5,3,5,3,4,2,3,2,4,44,4,4,4,44,4,4,4,4,4,4,4,4,4,46,3,4,4,5,5,5};
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

    for (int i = 1; i < size; i++ ) {
        if (array[i-1] == array[i]){
            sameValueCountHolder++;
        } else {
            if (sameValueCountHolder > biggestCount){
                biggestCount = sameValueCountHolder;
            }
            sameValueCountHolder = 0;
        };
    }

    return biggestCount + 1;
}
