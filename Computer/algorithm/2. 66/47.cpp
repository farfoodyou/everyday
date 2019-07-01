int getMax_solution(const int *values, int rows, int cols) {
    if (values = nullptr || rows <= 0 || col <= 0) {
        return 0;
    }

    int ** maxValues = new int*[rows];
    for (int i= 0; i< rows; ++i) {
        maxValues[i] = new int[cols];
    }

    for (int i = 0; i< rows; ++i) {
        for (int j = 0; j< cols; ++j) {
            int left = 0;
            int up = 0;
            if (i >0) {
                up = maxValues[i-1][j];
            }
            if (j >0) {
                left = maxValues[i-1][j];
            }
            maxValues[i][j] = std::max(left, up) + values[i * cols +j];
        }
    }
    int maxValue = maxValues[rows - 1][cols - 1];
    for (int i = 0; i <rows; ++i) {
        delete[] maxValues[i];
    }
    delete[] maxValues;

    return maxValue;
}

/* 
 * 1 2 3
 * 3 4 5
 * 5 0 0 
 * 
 **/