#include <stdio.h>
#include <stdbool.h>


struct screen getEmptyScreen();
bool isValidArgs(int size, int colPos, int rowPos);
void printArrayOnScreen(int size, int array[size], int colPos, int rowPos);
char castToChar(int i);
void printScreen(struct screen);

int SCREEN_ROWS = 10;
int SCREEN_COLS = 50;

struct screen {
    char a[10][50];
};

int main() {
    
    int arr[5] = {1,2,3,4,5};

    printArrayOnScreen(5, arr, 5, 4);

    return 0;
}

char castToChar(int i){

    switch (i) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        default: return ' ';
    }
}

void printArrayOnScreen(int size, int array[size], int colPos, int rowPos){

    if (isValidArgs(size, colPos, rowPos)){

        struct screen instance = getEmptyScreen();

        for (int i = 0; i < size; i++){
            instance.a[rowPos][i+colPos] = castToChar(array[i]);
        }

        printScreen(instance);
    }
}

bool isValidArgs(int size, int colPos, int rowPos){

    if (size > SCREEN_COLS){
        printf("ARRAY SIZE GREATER THAN COLUMNS COUNT!!! CANT PRINT ARRAY! PLEAS FIX ARRAY SIZE\n");
        return false;
    }

    if (colPos > SCREEN_COLS){
        printf("colPos GREATER THAN COLUMNS COUNT!!! CANT PRINT ARRAY!\n");
        return false;
    }

    if (rowPos > SCREEN_ROWS){
        printf("rowPos GREATER THAN COLUMNS COUNT!!! CANT PRINT ARRAY!\n");
        return false;
    }

    return true;
}

struct screen getEmptyScreen() {

    struct screen instance;

    for (int a = 0; a < SCREEN_ROWS; a++){

        for (int i = 0; i < SCREEN_COLS; i++){

            instance.a[a][i] = ' ';
        }
    }

    return instance;
}


void printScreen(struct screen str){

    for (int a = 0; a < SCREEN_ROWS; a++){

        printf("%d", a);

        for (int i = 0; i < SCREEN_COLS; i++){

            if (a == 0){
                printf("%d", i);
            }

            if (i == SCREEN_COLS - 1){
                printf("%c\n", str.a[a][i]);
            } else {
                printf("%c", str.a[a][i]);
            }

        }
    }
}


