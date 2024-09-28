class MyCircularDeque {
public:
    vector<int>v;
    int front,rear,size,cap;
    MyCircularDeque(int k) {
        v=vector<int>(k,-1);
        front=rear=size=0;
        cap=k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return 0;
        if(front==0)
            front=cap-1;
        else
            --front;
        v[front]=value;
        ++size;
        return 1;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return 0;
        v[rear]=value;
        if(rear==cap-1)
            rear=0;
        else
            ++rear;
        ++size;
        return 1;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return 0;
        v[front]=-1;
        if(front==cap-1)
            front=0;
        else
            ++front;
        --size;
        return 1;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return 0;
        if(rear==0)
            rear=cap-1;
        else
            --rear;
        v[rear]=-1;
        --size;
        return 1;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return v[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        if(rear==0)
            return v[cap-1];
        else
            return v[rear-1];
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==cap);
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