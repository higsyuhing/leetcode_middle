class Solution {
public:
    int rob(vector<int>& nums) {
        // note that if 3 continued number are not chosed to get robbed, 
        //      this is not optimal, the middle one can choose to be robbed. 
        // now, given dp array of 2 cases: 
        // 0: rob, thus no rob last one; 0: not rob, can rob last one
        
        // check this sol, and Q: 198
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
