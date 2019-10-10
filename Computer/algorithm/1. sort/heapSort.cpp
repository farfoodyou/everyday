
// 从小到大排序, 利用最大堆每次从未排序区取最大值.
void HeapSort(int *arr, int len){
    int i;
    for(i = len / 2 - 1; i >= 0; --i){
        Heapify(arr, i, len);
    }

    for(i = len - 1; i > 0; --i){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        Heapify(arr, 0, i);
    }
}

//最大堆, 堆顶是最大值
void Heapify(int *arr, int first, int last){
    int father = first;
    int son = father * 2 + 1;
    while(son < last){
        if(son + 1 < last && arr[son] < arr[son + 1]) ++son;  //如果右儿子大就选择右儿子

        if(arr[father] > arr[son])break; // 
        else{
            int temp = arr[father];
            arr[father] = arr[son];
            arr[son] = temp;
            father = son;
            son = 2 * father + 1;
        }
    }
}
