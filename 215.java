class Solution {
    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> minHeap = new PriorityQueue<>();
        for (int n: nums) {
            minHeap.add(n);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }
        return minHeap.peek();
        
        /*
        // I like this one, ops, they are same.. 
        
        for(int i:nums) {
            minHeap.add(i);
            
            if(minHeap.size() > k) {
                minHeap.remove();
            }
        }
        return minHeap.remove();
        
        */
        
    }
}
