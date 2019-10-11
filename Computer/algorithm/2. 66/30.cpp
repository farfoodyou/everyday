/*
 * 题目: 包含min函数的栈
 * 输入参数: 
 * 输出参数: 
 * 返回结果: 
 * 描述: 实现一个能包含最小元素的栈
 * 例如: 
 * 思路: 
 * 注意事项: 
*/
template<typename T>void StackWithMin<T>::push(const T&value){
    m_data.push(value);
    if(m_min.size() == 0) || value < m_min.top(){
        m_min.push(value);
    } else {
        m_min.push(m_min.top());
    }
}

template<typename T>void StackWithMin<T>::pop(){
    assert(m_data.size()>0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

template<typename T>const T& StackWithMin<T>::min() const {
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.pop();
}

