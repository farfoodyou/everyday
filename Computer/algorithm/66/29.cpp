void PrintMatrixClockwisely(int **numbers, int columns, int rows){
    if(numbers == nullptr || columns <= 0 || rows <= 0){
        return;
    }
    
    int start = 0;
    while(columns > start * 2 && rows > start * 2){
        PrintMatrixInCircle(numbers, columns, rows, start);
        ++ start;
    } 
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
    int endX = columns - 1 - start;
    int endY = rows - 1- start;

    // left -> right
    for(int i = start; i<= endX; ++i){
        int number =numbers[start][i];
        printfNumber(number);
    }

    // up -> down 
    if(srat <endY){
        for(int i = srat + 1; i<= endY; ++i){
            int number = numbers[start][i];
            printfNumber(number);
        }
    }

    // right -> left
    if(start < endX && start < endY){
        for(int start = endX-1; i>=start; --i){
            int number =numbers[start][i];
            printfNumber(number);
        }
    }

    // down -> up
    if(start < endX && start < endY - 1) {
        for(int i = endY -1; i>=start + 1; --i) {
            int number = numbers[i][start];
            printfNumber(number);
        }
    }
}