class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int peekEle;
    
    MyQueue() {
        
    }
    
    // T.C. = O(1), S.C. = O(n)
    void push(int x) {
        // Saving first element in s1 as peek element
        if(s1.empty())
            peekEle = x;
        s1.push(x);   // T.C. = O(1)
    }
    
    // Amortized T.C. = O(1)    (Most of the operations taken O(1) compared to O(n))
    // S.C. = O(1)
    int pop() {
        if(s2.empty()) {           // T.C. = O(n)
            // Move all elements from s1 to s2
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int poppedEle = s2.top();   // T.C. = O(1)
        s2.pop();                   
        return poppedEle;
    }
    
    // T.C. = O(1), S.C. = O(1)
    int peek() {
        // If s2 is not empty, return top of s2
        if(!s2.empty()) {       
            return s2.top();    // T.C. = O(1)
        }

        return peekEle;         // T.C. = O(1)
    }
    
    // T.C. = O(1), S.C. = O(1)
    bool empty() {
        return s1.empty() && s2.empty();
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