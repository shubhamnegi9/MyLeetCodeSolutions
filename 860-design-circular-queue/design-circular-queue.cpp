class MyCircularQueue {
public:
    int* q;
    int front;
    int rear;
    int size;
    int currSize;

    MyCircularQueue(int k) {
        q = new int[k];     // Initialized circular queue of size k
        front = -1;
        rear = -1;
        size = k;
        currSize = 0;
    }
    
    bool enQueue(int value) {
        if(currSize == size)
            return false;
        
        if(currSize == 0)         // or if(rear == -1)
            front = rear = 0;
        else 
            rear = (rear+1)%size;
        
        q[rear] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(currSize == 0)
            return false;

        int x = q[front];       // Popped element which can be returned if asked

        if(currSize == 1)
            front = rear = -1;
        else
            front = (front+1)%size;
        
        currSize--;
        return true;
    }
    
    int Front() {
        if(currSize == 0)
            return -1;
        return q[front];
    }
    
    int Rear() {
        if(currSize == 0)
            return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return (currSize == 0);
    }
    
    bool isFull() {
        return (currSize == size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */