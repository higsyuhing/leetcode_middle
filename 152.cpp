class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // the key is the two direction scaning......
        int len = nums.size(); 
        if(len == 0) return 0; 
        
        int left, leftm, right, rightm; 
        
        left = nums[0];
        right = nums[len-1];
        leftm = left; rightm = right; 
        
        for(int i = 1; i < len; i++){
            if(left == 0) left = 1;
            left = left * nums[i]; 
            leftm = max(left, leftm);
        }
        
        for(int i = len-2; i >= 0; i--){
            if(right == 0) right = 1;
            right = right * nums[i];
            rightm = max(right, rightm);
        }
        
        return max(leftm, rightm);
        
        
        
        /*
        
        // if meet 0, then seperate the vector
        // if meet negative number, hold it. 
        // use 0 to partition vector into sections
        // each section is partitioned into +x,-y,+x,-y...
        // then each section can be processed in a sequential order
        // (+left) (neg1) (+right) | curr
        
        int i; 
        int left, neg, right, state, curr, max, init; 
        // state = 0: left mul number
        // state = 1: meet a neg, right mul number
        // if meet another neg, merge all and state = 0
        // if meet 0, decide a side and compare with max
        
        state = 0; left = 0; neg = 0; right = 0; 
        curr = 0; max = 0; init = 1; 
        // init is avoiding pure negative answer, like [-1]
        
        int len = nums.size(); 
        for(i = 0; i < len; i++){
            curr = nums[i]; 
            if(curr == 0){
                if(state == 0){
                    if(init){
                        max = left; // no matter left is 0 or not
                        init = 0; 
                    }
                    else if(left > max) max = left; 
                }
                else{
                    // the guaranteed thing is: contain negative
                    if(right > left) left = right; 
                    if(init){
                        max = left; // meet 0 already
                        init = 0; 
                    }
                    else if(left > max) max = left; 
                    // clean up, pt1
                    neg = 0; 
                    right = 0; 
                }
                
                // clean up all
                state = 0; 
                left = 0; 
                continue; 
            }
            
            if(curr > 0){
                if(state == 0){
                    if(left == 0) left = curr; 
                    else left *= curr; 
                }
                else{
                    if(right == 0) right = curr; 
                    else right *= curr; 
                }
            }
            else{
                if(state == 0){
                    neg = curr; 
                    state = 1; 
                }
                else{
                    if(left == 0) left = 1; 
                    if(right == 0) right = 1; 
                    left = left * neg * right * curr; 
                    state = 0; 
                    neg = 0; 
                    right = 0; 
                }
            }
            
            //cout << left << "\t" << neg << "\t" << right << "\t" << max << endl; 
        }
        
        if(state == 0){
            if(init){
                max = left; // [3]
            }
            else if(left > max) max = left; // [2,0,3]
        }
        else{
            if(right > left) left = right; 
            if(init){
                if(left == 0) max = neg; 
                else max = left; 
            }
            else if(left > max) max = left; 
        }
        
        return max; 
        */
    }
};
