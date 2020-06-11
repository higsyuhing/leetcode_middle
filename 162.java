public class Solution {
    public int findPeakElement(int[] nums) {
        
        return search(nums, 0, nums.length - 1);
    }
    public int search(int[] nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
}

/*
this solution is incorrect: 
1. agree that it's tricky that the [-1] and [n] is -inf, thus if the mid point
    is not-equal, it's guaranteed a peak point. but.. 
2. for case equal, it's incorrect. Saying the [mid] == [mid+1], thus it will goes right.. 
3. counter case: 
    1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    the testcase and solution are not considering this case.. 

*/


