
/* 
 * 输入参数: 数组地址, 数组长度, 找到的重复的元素
 * 输出参数: 一个数组是否含有重复元素
 * 描述: 如果不存在重复的元素一定所有的都有 number[i] = i; 如果缺少了那一定存在重复元素
 * 
*/
bool duplicate(int numbers[], int length, int* duplication){
    if(numbers==nullptr || length <=0){
        return false;
    }
    for(int i = 0; i < length; ++i) {
        if (numbers[i] < 0 || numbers[i] > length -1){
            return false;
        }
    }
    for (int i =0; i<length; ++i){
        while(numbers[i] !=i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            std::swap(numbers[i],numbers[numbers[i]]);
        }
    }
    return false;
}