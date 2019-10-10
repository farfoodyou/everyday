/* 
 * 题目: 机器人的运动范围
 * 输入参数: 整数n
 * 输出参数: 
 * 返回结果: 第n个斐波那契数
 * 描述: 用递归的方式求出第n个斐波那契数
 * 
*/
int movingCount(int threshold, int rows, int cols) {
    if(threshold < 0 || rows <= 0 || cols <=0) {
        return 0;
    }
    bool * visited = new bool[rows * cols];
    for(int i = 0; i<rows * cols; ++i){
        visited[i] = false;
    }

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;
    return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool * visited) {
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited)) {
        visited[row * cols + col ] =true;
        colunt = 1 + movintCountCore(threshold ,rows, cols, row -1, col visited) + movintCountCore(threshold ,rows, cols, row +1, col visited) + movintCountCore(threshold ,rows, cols, row, col-1 visited) + movintCountCore(threshold ,rows, cols, row, col+1 visited);
    }
    return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited) {
    if(row >= 0 && row < rows && col >= 0 && col < cols
        && getDigitSUm(row) + getDigitSum(col) <= threshold && ! visited[row * cols + col]) {
            return true;
        }
    return false;
}

int getDigitSum(int number) {
    int sum  = 0;
    while(nubmert >0){
        sum += number%10;
        number /=0;
    }
    return sum;
}
