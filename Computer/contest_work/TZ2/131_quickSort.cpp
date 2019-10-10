#include <iostream>
using namespace std;
const int MAX = 5e5;
const int SENTINEL = 2e9;

int L[MAX/2+2], R[MAX/2+2];

int partition(int A[], int n, int p, int r){
    int i, j;
    int t, x;
    x = A[r];
    i = p - 1;
    for ( j = p ; j < r; j++) {
        if(A[j]  <= x) {
            i++;
            std::swap(A[i],A[j]);
        }
    }
    std::swap(A[i+1],A[r]);
    return i+1;
}

void quickSort(int A[], int n, int p, int r){
    int q;
    if (p < r){
        q = partition(A, n, p, r);
        quickSort(A, n, p, q-1);
        quickSort(A, n, q+1, r);
    }
}

int main(){
    int A[MAX], n, i;
    cnt = 0;

    cin >> n;
    for (i = 0; i< n; i++) cin >> A[i];

    quickSort(A, n, 0, n-1);

    for (i = 0; i < n; i++){
        if(i)cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
