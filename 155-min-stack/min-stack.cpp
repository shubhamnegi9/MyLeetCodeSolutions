class MinStack {
public:
    stack<long> st;
    long mini = INT_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if(val < mini) {
                st.push((long)2*val - mini);      // Push modified value in stack
                mini = val;                       // Replace mini with smaller value
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;

        long x = st.top();
        st.pop();

        if(x < mini) {
            mini = 2*mini - x;      // Restoring previous value of mini
        }
    }
    
    int top() {
        if(st.empty())
            return -1;

        long x = st.top();

        if(x < mini) {
            return mini;            // Return mini as top of stack for modified array
        } else {
            return x;               // Return x as top of stack
        }
    }
    
    int getMin() {
        return mini;
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