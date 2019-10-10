/*
 * 输入参数: 二维字符数组, 行数, 列数, 字符串
 * 输出参数: 
 * 返回结果: 是否存在该数组
 * 描述: 用DFS搜索在一个二维数组中查找是否存在某字符串
 * 
*/
bool hasPath(char* mastrix, int rows, int cols, char* str){
    if(matrix == nullptr || rows < 1 || cols < 1 || str==nullptr) {
        return false;
    }

    bool *visited = new bool[rows * cols];
    memset(visited, 0 , rows * cols);

    int pathLength = 0;
    for (int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            if (hasPathCore(matrix, rows ,cols, row, col, str, 
                pathLength, visited)){
                    return true;
                }
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool *visited) {
    if(str[pathLength] == '\0') {
        return true;
    }

    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col <cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col]) {
            ++pathLength;
            visited[row * cols + col] = true;
            hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row -1 , col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
            if(hasPath) {
                --pathLength;
                visited[row * cols + col] = false;
            }

        }
        
    return hasPath;
}