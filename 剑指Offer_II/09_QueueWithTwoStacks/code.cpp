template<typename T>class CQueue
{
    public:
        CQueue();
        ~CQueue();

        void appendTail(const T& node);
        T deleteHead();
    
    private:
        stack<T> stack1;
        stack<T> stack2;
};
template<typename T>void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}
template<typename T>void CQueue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(stack1.size()>0)
        {
            T& data=stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0)
        throw new exceptions("queue is empty");

    T head=stack2.top();
    stack2.pop();
    return head;
}