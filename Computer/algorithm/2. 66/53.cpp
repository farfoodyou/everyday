/*
 * 题目: 在排序数组中查找数字
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 在排序数组中查找对应数字出现的次数
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
int GetFirstK(int* data, int length, int k, int start, int end){
    if(start > end){
        return -1;
    }
    int middleIndex = (start + end) / 2;
    int middleDdata = data[middleIndex];

    if(middleData == k){
        if((middleIndex > 0 && data[middleIndex - 1] != k)
            || middleIndex == 0){
            return middleIndex;
        } else {
            end = middleIndex - 1;
        }
    } else if(middleData > k){
        end = middleIndex - 1;
    } else {
        start = middleIndex + 1;
    }
    return GetFirstK(data, length, k, start, end);
}


int GetLastK(int* data, int length, int k, int start, int end){
    if(start > end){
        return -1;
    }
    int middleIndex = (start + end) / 2;
    int middleDdata = data[middleIndex];

    if(middleData == k){
        if((middleIndex < length -1 && data[middleIndex + 1] != k)
            || middleIndex == length - 1){
            return middleIndex;
        } else {
            end = middleIndex + 1;
        }
    } else if(middleData < k){
        end = middleIndex + 1;
    } else {
        start = middleIndex - 1;
    }
    return GetLastK(data, length, k, start, end);
}

int GetNumber(int* data, int length, int k){
    int number = 0;
    if(data != nullptr && length > 0){
        int first = GetFirstK(data, length, k, 0, length -1);
        int last = GetLastK(data, length k, 0, length -1 );
        if(first > -1 && last > -1) {
            number = last - first + 1;
        }
    }
    return number;
}
