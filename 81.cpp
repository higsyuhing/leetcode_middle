class Solution {
public:
    
    bool helpfunc2(vector<int>& nums, int target, int l, int r){
        //cout << "hf2: " << l << '\t' << r << endl; 
        if(l > r) return false; 
        if(target < nums[l]) return false; 
        if(target > nums[r]) return false; 
        int mid = (l+r)/2; 
        if(nums[mid] == target) return true; 
        if(nums[mid] > target)
            return helpfunc2(nums, target, l, mid-1); 
        return helpfunc2(nums, target, mid+1, r); 
    }
    
    bool helpfunc1(vector<int>& nums, int target, int l, int r){
        //cout << "hf1: " << l << '\t' << r << endl; 
        if(l > r) return false; 
        if(l == r){
            if(nums[l] == target)
                return true; 
            else
                return false; 
        }
        int mid = (l+r)/2; 
        if(nums[mid] < nums[l])
            return (helpfunc1(nums, target, l, mid-1) || helpfunc2(nums, target, mid, r)); 
        else if(nums[mid] > nums[l])
            return (helpfunc2(nums, target, l, mid) || helpfunc1(nums, target, mid+1, r)); 
        else
            return (helpfunc1(nums, target, l, mid) || helpfunc1(nums, target, mid+1, r)); 
    }
    
    bool search(vector<int>& nums, int target) {
        // helpfunc1 handles rotated, helpfunc2 handles non-rotated
        return helpfunc1(nums, target, 0, nums.size()-1); 
        
    }
};
