class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        // why this is middle? 
        
        int start, curr, next; 
        int i; 
        vector<string> res; 
        if(nums.size() == 0) return res; 
        
        start = nums[0]; 
        curr = start; 
        i = 1; 
        while(i < nums.size()){
            next = nums[i]; 
            
            if((curr+1) == next){
                curr = next; 
                i++; 
                continue; 
            }
            
            // keep the record, start->curr, start' = next
            if(start == curr) res.push_back(to_string(start)); 
            else res.push_back(to_string(start) + "->" + to_string(curr)); 
            start = next; 
            curr = next; 
            i++; 
        }
        
        if(start == curr) res.push_back(to_string(start)); 
        else res.push_back(to_string(start) + "->" + to_string(curr)); 
        return res; 
    }
};
