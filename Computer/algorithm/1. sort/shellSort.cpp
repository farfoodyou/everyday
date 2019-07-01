void shellSort(int *arr, int len){
    int gap, i, j, temp;
    for(gap = len/2; gap > 0; gap /= 2){
        for(i = gap; i< n; i++){
            for(j = i- gap; j >= 0 && arr[j] > arr[j + gap]; j-= gap){
                temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
            }
        }
    }
}
