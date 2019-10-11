
/*
 * 题目: 最小的 k个数
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 输入n个数, 找出最小的 k 个数
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
void GetLeastNumbers(int *input,int n,int *output,int k){
    if(intput == nullptr || output == nullptr || k >n || n<=0|| k<=0) {
        return ;
    }
    int start = 0;
    int end = n - 1;
    int index = Partion(intput, n, start, end);
    while(index != k - 1) {
        if(index > k -1) {
            end = index - 1;
            index = Partion(input, n, start, end);
        } else {
            start = index + 1;
            index = Partion(input, n, start, end);
        }
    }
    for(int i = 0; i< k; i++){
        output[i] = input[i];
    }
}

/*
 这种方法会改变原数组
*/
