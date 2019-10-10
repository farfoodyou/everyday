#include <iostream>
using namespace std;
const int MAX = 2e6;

int H, A[MAX + 1];

void maxHeapify(int i){
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    // 从左子结点, 自身, 右子结点中选出值最大的结点
    if(l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    if(r <= H && A[r] > A[largest]) largest = r;

    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int main(){
    cin >> H;

    for (int i = 1; i <=H; i++) cin >> A[i];

    // 这只是建立堆的过程.
    for (int i = H; i >= 1; i--) maxHeapify(i);

    for (int i = 0; i<=H; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}
