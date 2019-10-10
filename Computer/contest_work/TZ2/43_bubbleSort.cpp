#include <cstdio>
#include <algorithm>

/* 按顺序输出数组元素 */
void trace(int A[], int N){
    int i ;
    for (i = 0; i< N; i++) {
        if (i> 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

/* 冒泡排序, 0起点数组*/
int bubbleSort(int A[], int N) {
    int sw = 0;
    bool flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                // 交换相邻元素
                std::swap(A[j], A[j- 1]);
                flag = 1;
                sw ++;
            }
        }
        trace(A, N);
    }
    return sw;
}

int main(){
    int N, i, j;
    int A[100];
    scanf("%d", &N);
    for(i = 0 ; i < N; i++) scanf("%d", &A[i]);

    trace(A, N);
    bubbleSort(A, N);

    return 0;

}
