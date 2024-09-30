class CustomStack {
public:
    vector<int> stk;
    int top;
    int size;
    
    CustomStack(int maxSize) {
        stk = vector<int>(maxSize, 0);
        top = -1;
        size = maxSize;
    }
    
    void push(int x) {
        if(top+1 < size) {
            top++;
            stk[top] = x;
        }
    }
    
    int pop() {
        if(top==-1) {
            return -1;
        }
        int val = stk[top];
        top--;
        return val;
    }
    
    void increment(int k, int val) {
        if(k <= top+1) {
            for(int i = 0; i < k; i++) {
                stk[i] += val;
            }
        }
        else {
            for(int i = 0; i <= top; i++) {
                stk[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */