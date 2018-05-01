void insertSort(int *arr, int len){
    int i,j;
    int temp;
    for(i = 1; i < len; i++){
        temp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > temp; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}