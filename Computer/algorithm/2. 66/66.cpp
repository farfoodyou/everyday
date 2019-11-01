/*
 * 题目: 构建乘积数组
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 构建乘积数组, 不能用除法
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void multiply(const vector<double>& array1, vector<double>& array2) {
    int length1 = array1.size();
    int length2 = array2.size();

    if(length1 == length2 && length2 > 1){
        array2[0] = 1;
        for(int i = 1; i < length1; ++i){
            array2[i] = array2[i -1] * array[i-1];
        }

        double temp = 1;
        for(int i = length1 - 2; i>=0 ; --i){
            temp *= array1[i+1];
            array2[i] *= temp;

        }
    }
}
