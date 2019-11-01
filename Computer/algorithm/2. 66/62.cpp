/*
 * 题目: 圆圈中最后剩下的数
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 0 到 n-1 绕成一个圈, 每次删除第 m个, 找出最后剩下的数
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int LastRemaining(unsigned int n, unsigned int m){
    if(n<1 || m<1) {
        return -1;
    }

    int last = 0;
    for(int i = 2; i<=n ;i++){
        last = (last + m) % i;
    }

    return last;
}
