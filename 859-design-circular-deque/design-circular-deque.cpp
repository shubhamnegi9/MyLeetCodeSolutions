class MyCircularDeque {
public:
    list<int> deq;
    int size;
    int K;
    
    MyCircularDeque(int k) {
        K = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        deq.push_front(value);
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        deq.push_back(value);
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        deq.pop_front();
        size--;
        return true;
    }
    
    bool deleteLast() {
         if(isEmpty()) {
            return false;
        }
        deq.pop_back();
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return deq.front();
    }
    
    int getRear() {
         if(isEmpty()) {
            return -1;
        }
        return deq.back();
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == K;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */