#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Тема: Работа со строками в Си
 * Лабораторная №4: вариант 13
 * Задача: "Перевернуть" в строке все слова. (Например: "Жили были дед и баба" - "илиЖ илиб дед и абаб").
 * Исполнил: Аветисян Арташес Робертович
 */

bool isValidSize(int size);

int main()
{
    char rowStr[] = "There are grandfather and grandmother";

    printf("CURRENT STRING: %s\n", rowStr);

    printf("PROCESSING...\n");


    char data [100][100];
    int dataElementsLength[100];
    int rowStrSize = strlen(rowStr);

    if (!isValidSize(rowStrSize))
    {
        return 0;
    }

    int letterIndex = 0;
    int startIndex = 0;
    int endIndex = 0;
    int reversedWordSize = 0;
    int wordIndex = 0;

    for(int i = 0; i < rowStrSize; i++){

        if ((rowStr[i] == 32) || (i == rowStrSize - 1)){
            endIndex = i - 1;
            reversedWordSize = endIndex - startIndex;
            int dataSingleElementLetterIndex = 0;
            for (int a = endIndex; a >= startIndex; a--){
                data[wordIndex][dataSingleElementLetterIndex] = rowStr[a];
                dataSingleElementLetterIndex ++;
            }
            dataElementsLength[wordIndex] = reversedWordSize;

            letterIndex = 0;
            startIndex = i + 1;
            wordIndex++;
        } else {
            letterIndex++;
        }

    }

    char reversedString[10000];
    int reversedStringIndex = 0;

    for (int i = 0; i < wordIndex; i++){
        for(int a = 0; a <= dataElementsLength[i]; a++){
            reversedString[reversedStringIndex] = data[i][a];
            reversedStringIndex++;
        }
        reversedString[reversedStringIndex] = 32;
        reversedStringIndex++;

        if (i == wordIndex - 1 ){
            reversedString[reversedStringIndex] = '\0';
        }
    }

    printf("RESULT: %s\n", reversedString);

    return 0;
}

bool isValidSize(int size)
{
    if (size > 5000){
        printf("WARNING! Process interrupted. The length of given string is too long, mast be less than 5000 symbols.\n");
        printf("Pleas, shorten the string and try again.\n");

        return false;
    }

    return true;
}