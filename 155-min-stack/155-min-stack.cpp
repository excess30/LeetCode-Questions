class MinStack {
public:
    
    stack<int>maxm;
    stack<int>minm;
    
    MinStack() {
        
    }
    
    void push(int val)
    {
        if(minm.empty()==true || minm.top()>=val)
        {
            minm.push(val);
        }
        maxm.push(val);
    }
    
    void pop() 
    {
        if(maxm.top()==minm.top())
        {
            minm.pop();
        }
        maxm.pop();
    }
    
    int top() 
    {
        return maxm.top();    
    }
    
    int getMin() 
    {
        return minm.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


