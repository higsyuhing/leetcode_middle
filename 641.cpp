class MyCircularDeque {
public:
    int *array; 
    int size, cap; 
    int head, tail; 

    MyCircularDeque(int k) {
        if (k <= 0){
            cout << "k <= 0: " << k << endl; 
            return; 
        }
        array = new int[k]; 
        size = k; 
        cap = 0; 
        head = 0; 
        tail = 0; 
    }
    
    bool insertFront(int value) {
        if (cap == size)
            return false; 
        head = (head - 1 + size) % size; 
        array[head] = value; 
        cap++; 
        return true; 
    }
    
    bool insertLast(int value) {
        if (cap == size)
            return false; 
        array[tail] = value; 
        tail = (tail + 1) % size; 
        cap++; 
        return true; 
    }
    
    bool deleteFront() {
        if (cap == 0)
            return false; 
        head = (head + 1) % size; 
        cap--; 
        return true; 
    }
    
    bool deleteLast() {
        if (cap == 0)
            return false; 
        tail = (tail - 1 + size) % size; 
        cap--; 
        return true; 
    }
    
    int getFront() {
        if (cap == 0)
            return -1; 
        return array[head]; 
    }
    
    int getRear() {
        if (cap == 0)
            return -1; 
        int index = (tail - 1 + size) % size; 
        return array[index]; 
    }
    
    bool isEmpty() {
        return (cap == 0); 
    }
    
    bool isFull() {
        return (cap == size); 
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
