class Solution {
public:
    
    bool inner_DFS(int target, vector<int>& hashkeys, map<int, int>& hashmap){
        if(target == 0) return true; 
        
        int i, key; 
        for(i = 0; i < hashkeys.size(); i++){
            if(hashkeys[i] <= target){
                key = hashkeys[i]; 
                if(hashmap[key] == 0) continue; 
                
                //curr.push_back(key); 
                hashmap[key]--; 
                bool ret = inner_DFS(target - key, hashkeys, hashmap); 
                if(ret) return true; // don't care, just ret
                
                hashmap[key]++; 
                //curr.pop_back(); 
            }
        }
        
        return false; 
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        map<int, int> hashmap; 
        vector<int> hashkeys; 
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; 
            if(hashmap.find(nums[i]) == hashmap.end()){
                hashmap[nums[i]] = 1; 
                hashkeys.push_back(nums[i]); 
            }
            else hashmap[nums[i]]++; 
        }
        
        if(sum%2 == 1) return false; 
        sort(hashkeys.begin(), hashkeys.end(), greater<int>()); 
        
        //vector<int> curr; 
        return inner_DFS(sum/2, hashkeys, hashmap); 
        
    }
};


/*

https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C%2B%2B-4-line-solution-using-a-bitset

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};

*/
