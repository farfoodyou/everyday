/*
 * 题目: 队列的最大值
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 给定一个数组, 和滑动窗口的大小, 找出滑动窗口的最大值.
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
vector<int> maxInWindows(const vector<int>& num, unsigned int size){
    vector<int> maxInWindows;
    if(num.size() >= size && size> 1){
        deque<int> index;
        for(unsigned int i = 0; i<size; ++i) {
            while(!index.empty() && num[i] >= num[index.back()]){
                index.pop_back();
            }
            intdex.push_back();
        }

        for(unsigned int i = size; i<num.size(); ++i){
            maxInWindows.push_back(num[index.front()]);

            while(!index.empty() && num[i] >= num[index.back()]){
                index.pop_back();
            }

            if(!index.empty() && index.front() <= (int)(i -size)){
                index.pop_front();
            }
            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}
