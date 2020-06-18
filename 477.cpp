class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // compute in statistic way.. 
        // for each bit position, saying (i_0) 0s, and (n - i_0) 1s
        // thus for all combinations, (i_0)*(n - i_0) 1s in hamming distance
        
        int len = nums.size(); 
        if(len < 2) return 0; 
        
        int bit1arr[32]; 
        int curr; 
        for(int i = 0; i < 32; i++) bit1arr[i] = 0; 
        for(int i = 0; i < len; i++){
            int j = 0; 
            curr = nums[i]; 
            while(curr){
                if(curr & 1) bit1arr[j]++; 
                curr = curr >> 1; 
                j++; 
            }
        }
        curr = 0; 
        for(int i = 0; i < 32; i++){
            curr += bit1arr[i] * (len - bit1arr[i]); 
        }
        
        return curr; 
    }
};
