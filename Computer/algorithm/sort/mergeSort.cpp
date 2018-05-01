
void Merge(int *arr, int *reg, int first, int last){
    if(first >= last)return ;
    int len = last - first, mid = (len >> 1) + first);

    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    Merge(arr, reg, first1, last1);
    Merge(arr, reg, first2, last2);

    int k = first;
    while(first1 <= last1 && first2 <= last2){
        reg[k++] = arr[first1] < arr[first2] ? arr[first1++] : arr[first2++];
    }

    while(first1 <= last1){
        reg[k++] = arr[first1++];
    }

    while(first2 <= last2){
        reg[k++] = arr[first2++];
    }

    for(k = first, k <= last; k++){
        arr[k] = reg[k];
    }
}

void MergeSort(int *arr, const int len){
    int reg[len];
    Merge(arr, reg, 0, len-1);
}
