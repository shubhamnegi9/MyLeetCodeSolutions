class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
         while(!s2.empty()) {
            int ele = s2.top();
            s2.pop();
            s1.push(ele);
        }
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()) {
            int ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
        int popped = s2.top();
        s2.pop();
        return popped;
    }
    
    int peek() {
        while(!s1.empty()) {
            int ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
        return s2.top();
    }
    
    bool empty() {
        while(!s1.empty()) {
            int ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */