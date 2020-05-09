class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // for every odd number, keep their left nums and right nums
        
        vector<int> oddinfo; // intervals between odds
        // [0,0,1,1,0,1,0] => [3,1,2,2]
        // representing how many left/right cases of sub-array
        
        int counter = 0; 
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & 1) == 0) counter++; // even, counter++
            else{
                // odd
                oddinfo.push_back(counter+1); 
                counter = 0; 
            }
        }
        oddinfo.push_back(counter+1); // last part
        
        counter = 0; 
        if(oddinfo.size() < (k+1)) return 0; 
        
        for(int i = 0; i < (oddinfo.size()-k); i++){
            // in example of [3,1,2,2], size: [0-4)
            // if k == 3, thus, only 3--2 will be counted
            // if k == 2, thus 3--2 and 1--2 will be counted
            counter += oddinfo[i]*oddinfo[i+k]; 
        }
        
        return counter; 
    }
};
