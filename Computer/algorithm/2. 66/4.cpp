/*
 * 输入参数: 数组地址, 行数, 列数, 要找的元素
 * 输出参数: 是否能找到对应元素
 * 描述: 在一个每行每列相对有序的二维数组中查找对应元素
 * 
*/
bool Find(int *matrix, int rows,int columns,int number){
    bool found = false;
    if(matrix !=nullptr && rows >0 && columns >0){
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0){
            if(matrix[row * columns + column] == number) {
                found = true;
                break;
            }
            else if(matirx[row * columns + column] > number){
                --column;
            } else {
                ++row;
            }
        }
    }
    return found;
}
