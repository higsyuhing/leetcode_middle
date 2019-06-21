class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> array; 
        char currchar; 
        for(int i = 1; i <= n; i++){
            currchar = '0' + i; 
            array.push_back(currchar); 
        }
        char resarray[10]; 
        resarray[n] = '\0'; 
        
        // perform this tricky process.. 
        int pos, val, temp1, temp2; 
        val = 1; 
        for(pos = 1; pos <= n; pos++) val *= pos; 
        pos = 0; 
        
        while(k > 0){
            if(n == pos) break; 
            val = val/(n - pos); 
            temp1 = (k-1) / val; 
            temp2 = (k-1) % val; 
            
            resarray[pos] = array[temp1]; 
            array.erase(array.begin()+temp1); 
            pos++; 
            k = temp2+1; 
            
            /*
            // no swap
            if(temp1 == 0){
                pos++; // temp2 equals to k
                continue; 
            }
            
            // swap happens
            swapchar = array[pos]; 
            array[pos] = array[pos+temp1]; 
            array[pos+temp1] = swapchar; 
            
            pos++; 
            k = temp2 + 1; 
            */
        }
        
        return string(resarray); 
        
        /*
        // use heap's algorithm
        // no, this is for printing all of them.. 
        if(k == 1){
            return string(array); 
        }
        
        */
        
        
    }
};
