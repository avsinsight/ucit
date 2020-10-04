/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: avs
 * Created on 13 сентября 2020 г., 1:07
 */

#include <cstdlib>
#include <stdio.h>
#include <conio.h>

int* selectionSort(int* array, int size);
int findMinimumPos(int* a, int start, int end);
void printArray(int* array, int size, char* label);
int* fillRandom(int* array, int size);
void printArrayWithColors(int* array, int size, int sortedBoderIndex);

int main(int argc, char** argv) {
    
    //int array[] = {5,3,9,2,6,3,8,3,0,2,6,2,8,2,4,5,6,2,3,4,3,42,1,23,5,67,78,8,9,0,65,1,25,8,8,43,3,876,543,1,23,4567,8,87,654,32};
    //int size = sizeof(array)/sizeof(array[0]);
    
    int size = 15;
    int newArr[size];
    
    int* filledArrayBegining = fillRandom(newArr, size);
    
    printArray(filledArrayBegining, size, "Generated array:");
        
    selectionSort(filledArrayBegining, size);
    
    return 0;
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
       
        
        int minimumPosition = findMinimumPos(array, i, size);
        temp = array[i];
        array[i] = array[minimumPosition];
        array[minimumPosition] = temp;
               
        printArrayWithColors(array, size, i);
        
    }
    
    return array;
}

void printArrayWithColors(int* array, int size, int sortedBoderIndex){

    delline();
    getch();
    
    
    printf("{");
    for (int i = 0; i < size; i++){
        
        if (i <= sortedBoderIndex){
            textcolor(GREEN);
        } else {
            textcolor(WHITE);
        }
        
        printf("%d ", array[i]);
        
    }
    printf("}\n");
    
}


void printArray(int* array, int size, char* label){

    printf(label);
    printf("{");
    for (int i = 0; i < size; i++){
        
        printf("%d, ", array[i]);
    }
    printf("}\n");
    
}

int findMinimumPos(int* a, int start, int end){
    
    //printf("first element of arrya %d, start %d end%d\n", a[0], start, end);
    
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