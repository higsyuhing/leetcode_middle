class Solution {
public:
    
    void helpfunc(vector<vector<int>>& ret, unsigned *helparr, int i, int k, int n){
        // do this level of loop..
        int j, l; 
        if(i != k){
            // not the last/leaf loop
            for(j = helparr[i-1]+1; j <= (n-k+i); j++){
                helparr[i] = j; 
                helpfunc(ret, helparr, i+1, k, n); 
            }
        }
        else{
            // the last one, create sub vector and insert
            for(j = helparr[i-1]+1; j <= (n-k+i); j++){
                helparr[i] = j; 
                vector<int> temp; 
                for(l = 1; l < (k+1); l++){
                    temp.push_back(helparr[l]); 
                }
                ret.push_back(temp); 
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ret; 
        // basic check
        if((k < 1) || (n < 1) || (n < k)) return ret; 
        
        unsigned *helparr = new unsigned[k+1]; 
        int i; 
        for(i = 0; i < (k+1); i++) helparr[i] = 0; 
        
        helpfunc(ret, helparr, 1, k, n); 
        
        return ret; 
        
        /*
        // if use recurive method, need a DP to avoid repeated calculation
        // use iterative for fast and less calculation
        
        vector<vector<int>> ret; 
        unsigned *helparr = new unsigned[n]; 
        int i, j, p, q, flag1, flag2; 
        for(i = 0; i < (n-k); i++) helparr[i] = 0; 
        for(i = n - k; i < n; i++) helparr[i] = 1; 
        
        i = 0; // the index for current output
        while(1){
            // transfer the helparr to a result
            ret.push_back(vector<int>()); 
            // write the output
            for(j = 0; j < n; j++)
                if(helparr[j]) ret[i].push_back(j+1); 
            
            // check and try if we can shift left
            
            
            
            
            i++; 
            
            
            flag1 = 1; flag2 = 1; 
            for(j = 0; j < n; j++){
                if(helparr[j]) ret[i].push_back(j+1); 
                if(flag1 && (helparr[j] == 0)){
                    p = j; 
                    flag1 = 0; 
                }
                if((!flag1) && flag2 && (helparr[j] == 1)){
                    q = j; 
                    flag2 = 0; 
                }
            }
            
            // update the helparr
            if(p == k) break; 
            helparr[p] = 1; 
            helparr[q] = 0; 
            i++; 
        }
        
        return ret; 
        */
    }
};
