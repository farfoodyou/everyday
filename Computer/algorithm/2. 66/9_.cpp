
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

