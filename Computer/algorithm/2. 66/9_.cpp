/*
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 用栈模拟队列
 * 
*/
template<typename T>calss CQueue {
    public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(cosnt T&node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T>T CQueue<T>::appendTail(const T& element){
    stack1.push(element);
}

template<typename T>T CQueue<T>::deleteHead(){
    if(stack2.size()<=0) {
        while(stack1.size()>0){
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0){
        throw new exception("queue is empty");
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}
