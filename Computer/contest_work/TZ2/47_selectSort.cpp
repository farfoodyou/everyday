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

/* 选择排序, 0起点数组*/
int selectionSort(int A[], int N) {
    int i, j, t, sw= 0, minj;
    // i表示排序区和未排序区的边界, [0,i) 表示已排序区 [i,N) 表示未排序区
    for (i = 0; i < N - 1; i++) {
        minj = i;
        // 找到未排序区最小的元素
        for ( j = i; j < N; j++) {
            if( A[j] < A[minj])minj = j;
        }
        // 将最小元素放在排序区末尾
        t = A[i]; A[i] = A[minj]; A[minj] = t;
        if (i != minj) sw ++;

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
    selectionSort(A, N);

    return 0;

}
