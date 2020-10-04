#include <stdio.h>
#include <string.h>

/**
 * Тема: Работа со строками в Си
 * Лабораторная №4: вариант 13
 * Задача: "Перевернуть" в строке все слова. (Например: "Жили были дед и баба" - "илиЖ илиб дед и абаб").
 * Исполнил: Аветисян Арташес Робертович
 *
 */


int main() {

    char rowStr[] = "There are grandfather and grandmother";

    printf("CURRENT STRING: %s\n", rowStr);
    printf("PROCESSING...\n");

//    Алгоритм:
//    разбить выражение на массив строк используя разделитель пробел
//    для каждого элемента в массиве выполнить обратный перебор букв
//    склеить все елементы массива с перевернутыми буквами в новуй строку

    //10 kb
    char data [100][100];
    int dataElementsLength[100];

    //длина строки для обработки
    int rowStrSize = strlen(rowStr);

    if (rowStrSize > 5000){
        printf("WARNING! Process interrupted. The length of given string is too long, mast be less than 5000 symbols.\n");
        printf("Pleas, shorten the string and try again.\n");
        return 0;
    }

    int letterIndex = 0;
    int startIndex = 0;
    int endIndex = 0;
    int reversedWordSize = 0;
    int wordIndex = 0;

    for(int i = 0; i < rowStrSize; i++){
        //printf("%c\n", rowStr[i]);

        //условия true если встречается пробел или последняя итерация
        if ((rowStr[i] == 32) || (i == rowStrSize - 1)){
            endIndex = i - 1;
            reversedWordSize = endIndex - startIndex;
            //printf("SPACE or END OF CHAR[] '%c', wordIndex = %d, currentStartIndex = %d, currentEndIndex = %d\n", rowStr[i], wordIndex, startIndex, endIndex);
            int dataSingleElementLetterIndex = 0;
            for (int a = endIndex; a >= startIndex; a--){
                data[wordIndex][dataSingleElementLetterIndex] = rowStr[a];
                //printf("WAS ADDED CHAR:  '%c'\n", rowStr[a]);
                dataSingleElementLetterIndex ++;
            }
            dataElementsLength[wordIndex] = reversedWordSize;

            letterIndex = 0;
            startIndex = i + 1;
            wordIndex++;
        } else {
            //printf("IN WORD, letterIndex: %d\n", letterIndex);
            letterIndex++;
        }

    }

//    for (int i = 0; i < 100; i++){
//        printf("NEW LINE IN DATA\n");
//        for (int a = 0; a < 100; a++){
//            printf("DATA letter: %c\n", data[i][a]);
//        }
//    }


    char reversedString[10000];
    int reversedStringIndex = 0;

    for (int i = 0; i < wordIndex; i++){
        //printf("wordIndex iteration = %d, \n", i);
        for(int a = 0; a <= dataElementsLength[i]; a++){
            //printf("dataElementsLength[i] = %d, \n", dataElementsLength[i]);
            reversedString[reversedStringIndex] = data[i][a];
            //printf("letter: %c, reversedStringIndex = %d\n", reversedString[reversedStringIndex], reversedStringIndex);
            reversedStringIndex++;
        }
        reversedString[reversedStringIndex] = 32;
        reversedStringIndex++;
    }

    printf("RESULT: %s\n", reversedString);

    //TODO: алгоритмическая сложность большая O(n) + O(n*n), алгоритм медленный

    return 0;
}