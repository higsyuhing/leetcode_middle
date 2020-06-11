class Solution {

    int[] w_sum;
    public Solution(int[] w) {
        w_sum = new int[w.length];
        int sum = 0;
        for(int i = 0; i < w.length; i++){
            sum += w[i];
            w_sum[i] = sum;
        }
    }
    
    public int pickIndex() {
        double target = w_sum[w_sum.length - 1] * Math.random();
        int si = 0, ei = w_sum.length - 1;
        int res = -1;
        while(si <= ei){
            int mid = (si + (ei - si) / 2);
            if(target < w_sum[mid]){
                res = mid;
                ei = mid - 1;
            }
            else{
                si = mid + 1;
            }
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

/*
discussed solution is good. 
https://leetcode.com/problems/random-pick-with-weight/discuss/671460/Detailed-Explanation-or-Summary-of-2-different-solutions

*/
