class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1; 
        if (nums.size() == 2){
            if (nums[0] == nums[1])
                return 1; 
            else
                return 2; 
        }

        int del = 0; 
        int wiggledir = -2; // init state, later it will be 1 or -1 or 0.. 
        int i = 2; // start index
        int last = nums[0]; 
        int curr = nums[1]; 
        if (last == curr){
            wiggledir = 0; 
            del++; // del nums[0]
        }
        else{
            wiggledir = (curr > last) ? 1 : -1; 
        }
        last = curr; 

        for (; i < nums.size(); i++){
            int curr = nums[i]; 
            if (wiggledir == 0){
                if (last == curr){
                    del++; // del last
                }
                else{
                    wiggledir = (curr > last) ? 1 : -1; 
                    last = curr; 
                }
            }
            else if (wiggledir == 1){
                if (last == curr){
                    del++; // del last
                }
                else if (last < curr){
                    del++; // del last
                    last = curr; 
                }
                else{
                    wiggledir = -1; 
                    last = curr; 
                }
            }
            else{ // -1
                if (last == curr){
                    del++; 
                }
                else if (last > curr){
                    del++; // del last
                    last = curr; 
                }
                else{
                    wiggledir = 1; 
                    last = curr; 
                }
            }
        }

        return (nums.size() - del); 

    }
};
