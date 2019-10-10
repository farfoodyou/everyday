/*
 * 输入参数: 数组地址, 数组长度
 * 输出参数: 一个数组是否含有重复元素
 * 描述: 不实用辅助数组, 不修改原数组, 通过二分查找找到某一个重复的元素
 * 
*/
int getDUplication(const int*numbers,int length){
    if(numbers ==nullptr || length <=0){
        return -1;
    }
    int start = 1;
    int end = length - 1;
    while(end >= start){
        int middile = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if(end == start) {
            if(count > 1){
                return start;
            } else {
                break;
            }
        }
        if (count >(middle - start + 1)){
            end = middle;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}
int countRange(const int* numbers,int length,int start , int end){
    if(numbers == nullptr) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i<length;i++ ){
        if(numbers[i] >= start && numbers[i] <= end){
            ++count;
        }
    }
    return count;
}

// nlogn
