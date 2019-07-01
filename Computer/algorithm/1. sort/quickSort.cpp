

void QuickSort(int *arr, int first, int last){
    int pivot = OnceSort(arr, first, last);
    QuickSort(arr, first, pivot - 1);
    QuickSOrt(arr, pivot + 1, last);
}

void OnceSort(int *arr, int first, int last){
    int i = first, j = last;
    while(i < j){
        while(i < j && arr[i] <= arr[j]) --j;
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        while(i < j && arr[i] <= arr[j]) ++i;
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    return i;
}
