class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // the nums[j] - nums[i] v.s. j-i will give a hint about 
        //  the missing numbers in between, thus binary search. 
        // what about if k is larger than all missing elements? 
        
        int l, r; // use [l, r)
        l = 0; r = nums.size(); 
        
        while (l < r){
            int m = (l+r)/2; 
            
            // check left-to-middle v.s. k
            int missleft = (nums[m] - nums[l]) - (m - l); 
            if (k <= missleft)
                r = m; 
            else {
                l = m; 
                k -= missleft; 
            }
            
            if (l == (r-1))
                return nums[l] + k; 
        }
        
        cout << "error?" << endl; 
        
        return 0; 
    }
};
