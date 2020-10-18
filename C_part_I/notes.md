void printScrean(int** array, int columnsCount, int rowsCount){
    
    for (int a = 0; a < columnsCount; a++){
    
        for (int i = 0; i < rowsCount; i++){
            
            if (i == rowsCount - 1){
                printf("%d\n", array[a][i]);
            } else {
                printf("%d", array[a][i]);
            }
            
        }
    }
    
}
