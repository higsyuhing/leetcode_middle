class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr, last, wcurr, temp1, i; 
        last = -1, wcurr = 0; 
        temp1 = 0; // flag for repeating
        
        for(i = 0; i < nums.size(); i++){
            curr = nums[i]; 
            
            // several cases here
            // 1. initial case
            if(i == 0){
                last = curr; 
                wcurr++; 
                continue; // for curr == -1
            }
            // 2. if repeat
            if(curr == last){
                // the first time meet repeat, write data and set flag
                if(temp1 == 0){
                    nums[wcurr] = curr; 
                    wcurr++; 
                    temp1 = 1; 
                }
                // more than 2 repeat, nothing todo
            }
            // diff value
            else{
                last = curr; 
                nums[wcurr] = curr; 
                wcurr++; 
                temp1 = 0; 
            }
        }
        
        return wcurr; 
    }
};
