class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int, int> countindexmap; 
        countindexmap[0] = -1; 
        int balance = 0; 
        int maxlen = 0; 
        
        for (int i = 0; i < nums.size(); i++){
            int curr = nums[i]; 
            balance += (curr*2 - 1); 
            if (countindexmap.count(balance) == 0){
                countindexmap[balance] = i; 
            }
            else{
                int len = i - countindexmap[balance]; 
                maxlen = (maxlen < len) ? len : maxlen; 
            }
            
        }
        
        return maxlen; 
    }
};


/*
stupid me.. 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        // f([i, j]) = sum of "1"
        // g([i, j]) = (sum of "1")*2 - (j - i) == 0? 
        
        int len = nums.size(); 
        if (len < 2) return 0; 
        
        vector<int> prefixsum(len); 
        int sum = 0; 
        for (int i = 0; i < len; i++){
            sum += nums[i]; 
            prefixsum[i] = sum; 
        }
        
        // for (int i = 0; i < len; i++) cout << prefixsum[i] << endl; 
        // cout << endl; 
        
        int dist = 0; 
        for (int i = 0; i < (len-1); i++){
            for (int j = i+1; j < len; j++){
                // range [i, j]
                // cout << i << "," << j << " - " << (prefixsum[j] - (prefixsum[i]))*2 << " : " << (j-i+1) << endl; 
                if ((prefixsum[j] - (prefixsum[i]-nums[i]))*2 == (j-i+1)){
                    dist = ((j-i+1) > dist) ? (j-i+1) : dist; 
                }
            }
        }
        
        return dist; 
    }
};


*/
