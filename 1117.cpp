class H2O {
private: 
    int numH, numO; 
    mutex lock; 
    condition_variable cvH, cvO, cv_trans; 
    int trans; 
    
public:
    H2O() {
        numH = 0; 
        numO = 0; 
        trans = 0; 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock ul(lock);    
        
        while (trans > 0)
            cv_trans.wait(ul); 
        
        numH++; 

        if ((numH < 2) || (numO < 1))
            cvH.wait(ul); 
        
        if ((numH >= 2) && (numO >= 1)){
            cvH.notify_one(); 
            cvO.notify_one(); 
            trans = 2; 
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        numH--; 
        trans--; 
        if (trans == 0) cv_trans.notify_all(); 
        
        ul.unlock(); 
        
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock ul(lock); 
        
        while (trans > 0)
            cv_trans.wait(ul); 
        
        numO++; 

        if ((numH < 2) || (numO < 1))
            cvO.wait(ul); 
        
        if ((numH >= 2) && (numO >= 1)){
            cvH.notify_one(); 
            cvH.notify_one(); 
            trans = 2; 
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        numO--; 
        trans--; 
        if (trans == 0) cv_trans.notify_all(); 
        
        ul.unlock(); 
        
    }
};


/*
class H2O {
private: 
    int numH, numO; 
    mutex lock; 
    condition_variable cvH, cvO, cv_trans; 
    int releaseH; // number of H should be released
    int releaseO; 
    int trans; 
    
public:
    H2O() {
        numH = 0; 
        numO = 0; 
        releaseH = 0; 
        releaseO = 0; 
        trans = 0; 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // static int id = 0; 
        // id++; 
        //cout << "H " << id << endl; 
        
        unique_lock ul(lock);    
        
        while (trans > 0)
            cv_trans.wait(ul); 
        
        numH++; 

        while (1){
            if (releaseH > 0) break; 
            if ((numH >= 2) && (numO >= 1)) break; // self check
            cvH.wait(ul); 
        }
        
        // cout << "H " << id << ":: " << numH << "," << numO << "," << releaseH << "," << releaseO << "," << trans << endl; 
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        numH--; 
        
        if (releaseH > 0){
            // a new O coming, need to release another H? 
            releaseH--; 
            trans--; 
            if (trans == 0) cv_trans.notify_all(); 
            if (releaseH > 0){
                cvH.notify_one(); 
            }
        }
        else{
            // here is a new H, need another H and a O. 
            releaseH = 1; 
            releaseO = 1; 
            cvH.notify_one(); 
            cvO.notify_one(); 
            trans = 2; 
        }
        
        ul.unlock(); 
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // static int id = 0; 
        // id++; 
        //cout << "O " << id << endl; 
        
        unique_lock ul(lock); 
        
        while (trans > 0)
            cv_trans.wait(ul); 
        
        numO++; 

        while (1){
            if (releaseH > 0) break; 
            if ((numH >= 2) && (numO >= 1)) break; // self check
            cvO.wait(ul); 
        }
        
        // cout << "O " << id << ":: " << numH << "," << numO << "," << releaseH << "," << releaseO << "," << trans << endl; 
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        numO--; 
        
        if (releaseO > 0){
            // a new H coming. 
            releaseO--; 
            trans--; 
            if (trans == 0) cv_trans.notify_all(); 
        }
        else{
            // here is a new O, need 2 H release. 
            releaseH = 2; 
            trans = 2; 
            cvH.notify_one(); 
        }
        
        ul.unlock(); 
    }
};
*/


/*
class H2O {
private: 
    int numH, numO; 
    mutex lock; 
    condition_variable cvH, cvO; 
    int releaseH; // number of H should be released
    int releaseO; 
    
public:
    H2O() {
        numH = 0; 
        numO = 0; 
        releaseH = 0; 
        releaseO = 0; 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock ul(lock); 
        numH++; 
        
        while (1){
            if (releaseH > 0) break; // here we have a new O coming
            if ((numH >= 2) && (numO >= 1)) break; // self check
            cvH.wait(ul); 
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        numH--; 
        
        if (releaseH > 0){
            // a new O coming, need to release another H? 
            releaseH--; 
            if (releaseH > 0){
                cvH.notify_one(); 
            }
        }
        else{
            // here is a new H, need another H and a O. 
            releaseH += 1; 
            releaseO += 1; 
            cvH.notify_one(); 
            cvO.notify_one(); 
        }
        
        ul.unlock(); 
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock ul(lock); 
        numO++; 
        
        while (1){
            if (releaseO > 0) break; 
            if ((numH >= 2) && (numO >= 1)) break; // self check
            cvO.wait(ul); 
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        numO--; 
        
        if (releaseO > 0){
            // a new H coming. 
            releaseO--; 
            if (releaseO > 0){
                cvO.notify_one(); 
            }
        }
        else{
            // here is a new O, need 2 H release. 
            releaseH += 2; 
            cvH.notify_one(); 
        }
        
        ul.unlock(); 
    }
};
*/

/*
while it is not passed, it is close enough to one of the solution in the discussion. 
that's enough for this question. 
*/
