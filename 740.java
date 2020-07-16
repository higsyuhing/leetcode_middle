class Solution {
    public int deleteAndEarn(int[] nums) {
        // you have a hash: unique-nums[i], #count
        // once you pick a num, you can get all unique-nums[i]*count points
        // then delete the hash unique-nums[i]-1, unique-nums[i]+1
        // then you can use DP for that, how to represent the state of hash? 
        // sol: using increasing order, then you have either take or not take
        //      the largest value.. 
        
        int[] count = new int[10001];
        for (int x: nums) count[x]++;
        int avoid = 0, using = 0, prev = -1;

        for (int k = 0; k <= 10000; ++k) if (count[k] > 0) {
            int m = Math.max(avoid, using);
            if (k - 1 != prev) {
                using = k * count[k] + m;
                avoid = m;
            } else {
                using = k * count[k] + avoid;
                avoid = m;
            }
            prev = k;
        }
        return Math.max(avoid, using);
    }
}
