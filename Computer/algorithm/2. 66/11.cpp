
/*
 * 输入参数: 整数数组, 数组长度
 * 输出参数: 
 * 返回结果: 第一个反转的数
 * 描述: 通过二分的方式找出输出旋转数组的最小元素
 * 
*/
int Min(int* numbers, int length){
    if(numbers ==nullptr || length <= 0){
        throw new std::exception("Invalid parameters");
    }

    int index1 = 0;
    int index2 = length -1;
    int indexMid = index1;
    while(numbers[index1] >= numbers[index2]) {
        if(index2 - index1 == 1){
            indexMide = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;

        if(numbers[index1] == numbers[index2]
            && numbers[indexMid] == numbers[index1]) {
                return MinInOrder(numbers, index1, index2);
            }

        if(numbers[indexMid] >= numbers[index1]){
            index1 = indexMid;
        } else if (numbers[indexMid] <=numbers[index2]) {
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2) {
    int result = numbers[index1];
    for (int i = index1 + 1; i<=index2; ++i) {
        if(result > numbers[i]) {
            result = numbers[i];
        }
    }
    return result;
}

