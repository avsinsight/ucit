#include <stdio.h>

/**
 * Изучение операторов, управляющих структур, работа с целочисленными массивами в Си
 * Лабораторная №2: вариант 13. Исполнил: Аветисян Арташес Робертович
 * 13. Найти в массиве наибольшее число подряд идущих одинаковых элементов
 * (например {1,5,3,6,6,6,6,6,3,4,4,5,5,5} = 5).
 */


int main() {

    //int rawData[] = {1,5,3,6,6,6,6,6,3,4,4,5,5,5};
    int rawData[] = {1,5,3,6,6,6,6,4,4,4,4,4,4,4,4,4,4,6,6,5,3,2,3,4,2,4,6,2,4,5,3,5,3,4,2,3,2,4,44,4,4,4,44,4,4,4,4,4,4,4,4,4,46,3,4,4,5,5,5};
    int rawDataArraySize = sizeof rawData / sizeof rawData[0];

    printf("CURRENT ARRAY ELEMENTS:\n");
    for (int a = 0; a < rawDataArraySize; a++ ){
        if (a!=rawDataArraySize-1) {
            printf("%d,", rawData[a]);
        } else {
            printf("%d", rawData[a]);
        }
    }

    printf("\nPROCESSING...\n");

    int biggestCount = 0;
    int sameValueCountHolder = 0;
    for (int i = 0; i < rawDataArraySize; i++ ) {
        if (i != 0){
            if (rawData[i-1] == rawData[i]){
                //printf("SAME: rawData[i-1]: %d, rawData[i]: %d\n", rawData[i-1], rawData[i]);
                sameValueCountHolder++;
                //printf("UPDATING: sameValueCountHolder =  %d\n", sameValueCountHolder);
            } else {
                //printf("NOT SAME: rawData[i-1]: %d, rawData[i]: %d\n", rawData[i-1], rawData[i]);
                if (sameValueCountHolder > biggestCount){
                    biggestCount = sameValueCountHolder;
                    //printf("UPDATING: biggestCount =  %d\n", biggestCount);
                }
                sameValueCountHolder = 0;
            };
            //printf("Element[%d] = %d, sameValueCountHolder: %d\n", i, rawData[i], sameValueCountHolder);
        }
    }
    printf("RESULT: biggestCount =  %d\n", biggestCount + 1);
    return 0;
}
