class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0; 
        int s311, s312, s321, s322; 
        // smallest number divided by 3 remaining 1 or 2, take 2 for each
        s311 = 100000; 
        s312 = 100000; // s311 >= s312
        s321 = 100000; 
        s322 = 100000; // s321 >= s322

        for (int num : nums){
            sum += num; 
            if (num % 3 == 1){
                if (num < s312){
                    s311 = s312; s312 = num; 
                }
                else if (num < s311){
                    s311 = num; 
                }
            }
            else if (num % 3 == 2){
                if (num < s322){
                    s321 = s322; s322 = num; 
                }
                else if (num < s321){
                    s321 = num; 
                }
            }
        }

        if (sum%3 == 0)
            return sum; 
        if (sum%3 == 1){
            if (s312 < (s321 + s322)){
                return (sum-s312); 
            }
            else{
                return (sum-s321-s322); 
            }
        }
        else{
            if (s322 < (s311 + s312)){
                return (sum-s322); 
            }
            else{
                return (sum-s311-s312); 
            }
        }
    }
};
