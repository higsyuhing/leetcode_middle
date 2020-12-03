class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //             [3.1] return true
        //      [2]
        //             [3.2] state = 1
        // [1]
        //             [3.3] state = 2
        //
        //
        //             [3.4] state = 3 => 1
        // [1]
        //             [3.5] state = 4 => 1
        //      [2]
        //             [3.6] state = 5
        
        int first, second, smallest, state; 
        if(nums.size() < 3) return false; 
        
        // init setting.. 
        first = nums[0]; second = nums[1]; 
        if(first < second){
            if(second < nums[2]) return true; 
            if(first >= nums[2]){
                smallest = nums[2]; 
                state = 2; 
            }
            else{
                second = nums[2]; 
                state = 1; 
                smallest = nums[0]; 
            }
        }
        else{
            if(first < nums[2]){
                second = nums[2]; 
                smallest = nums[1]; 
                first = nums[1]; 
                state = 1; 
            }
            else if(second >= nums[2]){
                smallest = nums[2]; 
                state = 5; 
            }
            else{
                first = nums[1]; 
                second = nums[2]; 
                smallest = nums[1]; 
                state = 1; 
            }
        }
        
        for(int i = 3; i < nums.size(); i++){
            int curr = nums[i]; 
            //cout << state << endl; 
            switch(state){
                case 1: 
                    if(second < curr) return true; 
                    if(first >= curr){
                        smallest = curr; 
                        state = 2; 
                    }
                    else{
                        second = curr; 
                    }
                    break; 
                case 2: 
                    if(second < curr) return true; 
                    if(curr > smallest){
                        first = smallest; 
                        second = curr; 
                        state = 1; 
                    }
                    else smallest = curr; 
                    break; 
                case 5: 
                    if(curr > smallest){
                        first = smallest; 
                        second = curr; 
                        state = 1; 
                    }
                    else{
                        smallest = curr; 
                    }
                    break; 
            }
        }
        
        return false; 
    }
};

// shit.. solution is much better........
/*
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first_num = Integer.MAX_VALUE;
        int second_num = Integer.MAX_VALUE;
        for (int n: nums) {
            if (n <= first_num) {
                first_num = n;
            } else if (n <= second_num) {
                second_num = n;
            } else {
                return true;
            }
        }
        return false;
    }
}
*/
