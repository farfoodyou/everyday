#include <iostream>
#include <algorithm>

// 这种写法先找到的是第一个? 没法确定吧? 没法确定.
int binarySearch(int A[], int N, int key){
    int left = 0, right = N;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == key) {
            return mid;
        } else if (A[mid] > key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    // 没有找到
    return -1;
}

int binarySearch(int A[], int N, int key){
    int left = 0, right = N;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (A[mid] >= key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (A[r] == key) {
        return r;
    }
    // 没有找到
    return -1;
}

int main(){
    int n = 100;
    int* const A = new int[n];

    for (int i = 0; i < n; i++) {
        A[i] = i * 2;
    }

    int value = 32;
    int* lpos = std::lower_bound(A, A + n, value);
    *(lpos+1) = value;
    int* upos = std::upper_bound(A, A + n, value);
    std::cout << "lpos: " << *lpos << std::endl;
    std::cout << "upos: " << *upos << std::endl;
    std::cout << "size: " << upos - lpos << std::endl;

    int my_pos = binarySearch(A, n, value);
    std::cout << "my_pos " << my_pos << std::endl;
    std::cout << "my_pos_value: " << A[my_pos] << std::endl;

    return 0;
}

/*


二分查找要考虑多个值得情况的话, 关键在于选取的中间值等于目标值时可以抛弃哪一段.
如果要获取最左边一个元素的下标, 在相等的情况下可以抛弃掉右边的区间;(l+r)/2 mid是不会是r的.
如果要获取最右边一个元素的下标, 在相等的情况下可以抛弃掉左边的区间;(l+r+1)/2 mid是不会是l的.

没有值得情况下如何输出大于的第一个未知, 

二分查找：当有多个元素值与目标元素相等时，返回最左边和最右边一个元素的下标 - qq_29762941的博客 - CSDN博客
https://blog.csdn.net/qq_29762941/article/details/83303692
*/