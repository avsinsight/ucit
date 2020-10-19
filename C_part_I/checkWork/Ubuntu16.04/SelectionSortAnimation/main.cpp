/* 
 * Author: Аветисян Арташес Робертович
 * Контрольная работа
 */

#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>


int* selectionSort(int* array, int size);
int findMinimumPos(int* a, int start, int end);
int* fillRandom(int* array, int size);
void showNumber(int number, int col, int row, int color);
void showArrayByNumder(int* array, int size, int col, int row, int color, 
        int firstElemPos, int secondElemPos);

int STEP = 3;
int INITIAL_ROW = 5;
int INITIAL_COL = 6;
int RANDOM_ARRAY_SIZE = 14;


int main(int argc, char** argv) {
        
    int newArr[RANDOM_ARRAY_SIZE];
    
    int* filledArrayBegining = fillRandom(newArr, RANDOM_ARRAY_SIZE);
    
    selectionSort(filledArrayBegining, RANDOM_ARRAY_SIZE); 
    
    return 0;
}

void showArrayByNumder(int* array, int size, int col, int row, int color, 
        int firstElemPos, int secondElemPos){
        
    for (int i = 0; i < size; i++){
        
        if((i == firstElemPos) || (i == secondElemPos)){
            showNumber(array[i], row-1, col + (i * STEP), color);
        } else {
            showNumber(array[i], row, col + (i * STEP), color);
        }
    }
    
}

void showNumber(int number, int col, int row, int color){
    
    textcolor(color);
    gotoxy(row, col);
    printf("%d", number);
    
}

int* fillRandom(int* array, int size){
    
    for (int i = 0; i < size; i++){
                
        array[i] = rand() % 50;
    }
    
    return array;
}

int* selectionSort(int* array, int size){

    int temp;
   
    for (int i = 0; i < size; i++){
        
        showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, WHITE, -1, -1);
        getch();
        showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, BLACK, -1, -1);
        
        int minimumPosition = findMinimumPos(array, i, size);
        
        showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, WHITE, i, minimumPosition);
        getch();
        showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, BLACK, i, minimumPosition);
        
        
        temp = array[i];
        array[i] = array[minimumPosition];
        array[minimumPosition] = temp;
        
        showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, WHITE, i, minimumPosition);
        getch();
        showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, BLACK, i, minimumPosition);
        
    }
    
    showArrayByNumder(array, size, INITIAL_COL, INITIAL_ROW, LIGHTGREEN, -1, -1);
    
    return array;
}


int findMinimumPos(int* a, int start, int end){
    
    int pos = start;
    int minimum = a[start];
    
    for (int i = start; i < end; i++){
        
        if ((i+1) != end ){
            
            if (minimum > a[i+1]){
                
                pos = i+1;
                minimum = a[i+1];
            }
        }
    }
    
    return pos;
}



