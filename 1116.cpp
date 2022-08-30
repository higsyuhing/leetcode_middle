/*
#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t sem_z, sem_o, sem_e; 

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem_z, 0 ,1);
        sem_init(&sem_o, 0 ,0);
        sem_init(&sem_e, 0 ,0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&sem_z);
            printNumber(0);
            if (i%2 == 0)
                sem_post(&sem_e);
            else
                sem_post(&sem_o);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+= 2) {
            sem_wait(&sem_e);
            printNumber(i);
            sem_post(&sem_z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+= 2) {
            sem_wait(&sem_o);
            printNumber(i);
            sem_post(&sem_z);
        }
    }
};
*/

//*
#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t sem0, sem1, sem2; 
    bool flag_next_odd; 
    // int curr; 

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem0, 0, 1); 
        sem_init(&sem1, 0, 0); 
        sem_init(&sem2, 0, 0); 
        flag_next_odd = true; 
        // curr = 0; 
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++){
        // while(1){
            sem_wait(&sem0); 

            // if (curr == n) return; 

            printNumber(0); 

            if (flag_next_odd){
                sem_post(&sem1); 
            }
            else{
                sem_post(&sem2); 
            }
            flag_next_odd = !flag_next_odd; 
        // }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+=2){
        // while(1){
            sem_wait(&sem2); 
            
            // if (curr == n){
            //     sem_post(&sem1); 
            //     sem_post(&sem0); 
            //     return; 
            // }
            
            // curr++; 
            // cout << curr; 
            printNumber(i); 
            
            sem_post(&sem0); 
        // }
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+=2){
        // while(1){
            sem_wait(&sem1); 
            
            // if (curr == n){
            //     sem_post(&sem2); 
            //     sem_post(&sem0); 
            //     return; 
            // }
            
            // curr++; 
            // cout << curr; 
            printNumber(i); 
            
            sem_post(&sem0); 
        // }
        }
    }
};
//*/

/*
class ZeroEvenOdd {
private:
    int n;
    mutex lock; 
    condition_variable cv; 
    bool flagz, flago, flage; 
    bool flag_next_odd; // tell zero who will be the next
    int curr; 

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        flagz = true; 
        flago = false; 
        flage = false; 
        flag_next_odd = true; 
        curr = 0; 
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(1){
            unique_lock ul(lock); 
            cv.wait(ul, [this](){return flagz;}); 

            if (curr == n){
                cv.notify_one(); 
                ul.unlock(); 
                // auto unlock since out of scope. 
                return; 
            }

            cout << "0"; 

            flagz = false; 
            if (flag_next_odd){
                flago = true; 
            }
            else{
                flage = true; 
            }
            flag_next_odd = !flag_next_odd; 

            ul.unlock(); 
            cv.notify_all(); 
        }
    }

    void even(function<void(int)> printNumber) {
        while(1){
            unique_lock ul(lock); 
            cv.wait(ul, [this](){return flage;}); 
            
            if (curr == n){
                flago = true; 
                flagz = true; 
                cv.notify_one(); 
                ul.unlock(); 
                return; // release the lock also
            }

            curr++; 
            //printNumber(curr); 
            cout << curr; 

            flage = false; 
            flagz = true; 

            ul.unlock(); 
            cv.notify_all(); 
        }
    }

    void odd(function<void(int)> printNumber) {
        while(1){
            unique_lock ul(lock); 
            cv.wait(ul, [this](){return flago;}); 

            if (curr == n){
                flage = true; 
                flagz = true; 
                cv.notify_one(); 
                ul.unlock(); 
                return; // release the lock also
            }
            
            curr++; 
            // printNumber(curr); 
            cout << curr; 

            flago = false; 
            flagz = true; 

            ul.unlock(); 
            cv.notify_all(); 
        }
    }
};
*/
