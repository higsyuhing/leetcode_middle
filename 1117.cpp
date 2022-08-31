class H2O {
    int numH, numO; 
    mutex lock; 
    condition_variable cvH, cvO; 
    bool trans; 
    int transH, transO; 
    
public:
    H2O() {
        numH = 0; 
        numO = 0; 
        trans = false; 
        transH = 2; 
        transO = 1; 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock ul(lock); 
        
        numH++; 
        
        while(1)
        {
            if ((trans == false) && ((numH >= 2) && (numO >= 1))) break; 
            if ((trans == true) && (transH > 0)) break; 
            cvH.wait(ul); 
        }
        
        trans = true; 
        numH--; 
        transH--; 
        
        if (transH > 0) cvH.notify_one(); 
        if (transO > 0) cvO.notify_one(); 
        if ((transH == 0) && (transO == 0))
        {
            trans = false; 
            transH = 2; 
            transO = 1; 
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock ul(lock); 
        
        numO++; 
        
        while(1)
        {
            if ((trans == false) && ((numH >= 2) && (numO >= 1))) break; 
            if ((trans == true) && (transO > 0)) break; 
            cvO.wait(ul); 
        }
        
        trans = true; 
        numO--; 
        transO--; 
        
        if (transH == 1) cvH.notify_one(); 
        else cvH.notify_all();  // <---- you must need to do this otherwise serialize in H-thread will make you LTE
        
        if ((transH == 0) && (transO == 0))
        {
            trans = false; 
            transH = 2; 
            transO = 1; 
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};

/*
class H2O {
private: 
    int numH, numO; 
    mutex lockH, lockO; 
    condition_variable cvH, cvO, cv_trans; 
    int transH, transO; 
    
public:
    H2O() {
        numH = 0; 
        numO = 0; 
        transH = 0; 
        transO = 0; 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock ul(lockH);    
        
        // while (trans > 0)
        //     cv_trans.wait(ul); 
        
        numH++; 
        
        if (transH > 0) goto label_releaseH; 

        if ((numH < 2) || (numO < 1))
            cvH.wait(ul); 
        
        if (transH > 0) goto label_releaseH; 
        
        if ((numH >= 2) && (numO >= 1)){
            cvH.notify_one(); 
            cvO.notify_one(); 
            transH = 2; 
            transO = 1; 
        }
        
label_releaseH: 
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        numH--; 
        transH--; 
        // if (trans == 0) cv_trans.notify_all(); 
        
        ul.unlock(); 
        
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock ul(lockO); 
        
        // while (trans > 0)
        //     cv_trans.wait(ul); 
        
        numO++; 
        
        if (transO > 0) goto label_releaseO; 

        if ((numH < 2) || (numO < 1))
            cvO.wait(ul); 
        
        if (transO > 0) goto label_releaseO; 
        
        if ((numH >= 2) && (numO >= 1)){
            cvH.notify_one(); 
            cvH.notify_one(); 
            transH = 2; 
            transO = 1; 
        }
        
label_releaseO: 
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        numO--; 
        transO--; 
        // if (trans == 0) cv_trans.notify_all(); 
        
        ul.unlock(); 
        
    }
};
*/

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
you must follow several places to make sure it can run through the test...... 
*/
