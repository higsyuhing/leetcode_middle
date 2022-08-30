#include <semaphore.h>

class BoundedBlockingQueue {
private: 
    int *array; 
    int head, tail; 
    sem_t sem_full, sem_empty; // number of elements, number of slots
    mutex lock; 
    int qsize; 
    int cap; 
    
public:
    BoundedBlockingQueue(int capacity) {
        array = new int[capacity]; 
        head = 0; tail = 0; 
        sem_init(&sem_full, 0, 0); 
        sem_init(&sem_empty, 0, capacity); 
        qsize = capacity; 
        cap = 0; 
    }
    
    void enqueue(int element) {
        sem_wait(&sem_empty); 
        // now we guaranteed have a space. 
        unique_lock ul(lock); 
        
        array[tail] = element; 
        tail = (tail + 1) % qsize; 
        cap++; 
        
        ul.unlock(); 
        sem_post(&sem_full); 
    }
    
    int dequeue() {
        sem_wait(&sem_full); 
        // now we guaranteed have a space. 
        unique_lock ul(lock); 
        
        int ret = array[head]; 
        head = (head + 1) % qsize; 
        cap--; 
        
        ul.unlock(); 
        sem_post(&sem_empty); 
        
        return ret; 
    }
    
    int size() {
        unique_lock ul(lock); 
        return cap; 
    }
};
