class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // do a incremental array with size+1
        // 0, a[0], a[0]+a[1], ..., sum[a]
        // then the sum of sub array = b[j] - b[i]
        
        vector<int> array; 
        int i, j, temp, len, res; 
        array.push_back(0); 
        temp = 0; 
        len = nums.size(); 
        for(i = 0; i < len; i++){
            temp += nums[i]; 
            array.push_back(temp); 
        }
        
        // how to find sum equals to k? normally it's n^2 for scaning i and j
        // we can pre-set a target and see if equal.. but same in ASM level
        // of course.. it has better solution: hash map.. 
        res = 0; 
        for(i = 0; i < len; i++){
            for(j = i+1; j < (len+1); j++){
                if((array[j] - array[i]) == k) res++; 
            }
        }
        
        return res; 
        
    }
};
