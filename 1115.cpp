#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t semfoo; 
    sem_t sembar; 

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&semfoo, 0, 1); 
        sem_init(&sembar, 0, 0); 
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&semfoo); 
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            sem_post(&sembar); 
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sembar); 
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            sem_post(&semfoo); 
        }
    }
};
