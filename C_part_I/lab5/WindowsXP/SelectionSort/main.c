/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Artashes
 *
 * Created on 11 сентября 2020 г., 22:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


int findMinimumPos(int* a, int start, int end);


int main(int argc, char** argv) {

    int array[] = {5,3,9,2,6,3,8,3,0,2,6,2,8,2,4,5,6,2,3,4,3,42,1,23,5,67,78,8,9,0,65,1,25,8,8,43,3,876,543,1,23,4567,8,87,654,32};
        
    int size = sizeof(array)/sizeof(array[0]);
    
    printf("INITIAL ARRAY:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
   
    int temp;
    
    for (int i = 0; i < size; i++){
        int minimumPosition = findMinimumPos(array, i, size);
        //printf("minimumPosition: %d\n", minimumPosition);
        temp = array[i];
        array[i] = array[minimumPosition];
        array[minimumPosition] = temp;
    }
    
    printf("SORTED ARRAY:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    
    return (EXIT_SUCCESS);
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


