#include <cstdio>
#include <vector>
const int maxn = 1e6;
long long cnt;
int l;
int A[maxn];
int n;
std::vector<int> G;

/* 按顺序输出数组元素 */
void trace(int A[], int N){
    int i ;
    for (i = 0; i< N; i++) {
        if (i> 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

/* 指定间隔插入排序, 0起点数组*/
void insertionSort(int A[], int N, int g) {
    int j, i, v;
    for (i= g; i< N; i++) {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt ++;
        }
        A[j + g] = v;
        trace(A, N);
    } 
}

void shellSort(int A[], int n){
    // 生成间隔序列
    for (int h = 1;;) {
        if (h > n) break;
        G.push_back(h);
        h = 3 * h + 1;
    }

    // 指定G[i] 为g
    for ( int i = G.size() - 1 ; i>= 0; i--){
        insertionSort(A, n, G[i]);
    }
}

int main(){
    int N, i, j;
    //int A[100];
    scanf("%d", &N);
    n = N;
    for(i = 0 ; i < N; i++) scanf("%d", &A[i]);

    trace(A, N);
    shellSort(A, N);

    return 0;

}
