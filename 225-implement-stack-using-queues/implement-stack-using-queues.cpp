class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size=q.size();
        while(size!=1){
            q.push(q.front());
            q.pop();
            size--;
        }
        int stack_top=q.front();
        q.pop();
        return stack_top;
    }
    
    int top() {
        int size=q.size();
        while(size!=1){
            q.push(q.front());
            q.pop();
            size--;
        }
        int stack_top=q.front();
        q.pop();
        q.push(stack_top);
        return stack_top;
    }
    
    bool empty() {
        return q.empty()==1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */