class Solution {
public:

    void helperPermu(vector<int>& nums, int start){
        if (start == (nums.size()-1))
            return; 
        
        // find a "<" pair
        int last = nums[nums.size()-1]; 
        int head = -1; 
        for (int i = nums.size()-2; i >= start; i--){
            int curr = nums[i]; 
            if (curr < last){
                head = i; 
                break; 
            }
            last = curr; 
        }

        //  if cannot find, reverse all
        if (head == -1){
            int left = start; 
            int right = nums.size()-1; 
            while (left < right){
                int tmp = nums[left]; 
                nums[left] = nums[right]; 
                nums[right] = tmp; 
                left++; 
                right--; 
            }
            return; 
        }

        // from head to the end, final the smallest one > head
        int index; 
        int val = 1000; // > 100 is ok
        for (int i = head+1; i < nums.size(); i++){
            int curr = nums[i]; 
            if ((curr > nums[head]) && (curr <= val)){
                val = curr; 
                index = i; 
            }
        }
        // swap head and that one
        nums[index] = nums[head]; 
        nums[head] = val; 

        // recursive do the next
        // helperPermu(nums, head+1); 
        int left = head+1; 
        int right = nums.size()-1; 
        while (left < right){
            int tmp = nums[left]; 
            nums[left] = nums[right]; 
            nums[right] = tmp; 
            left++; 
            right--; 
        }
    }


    void nextPermutation(vector<int>& nums) {
        // find a "<" pair, decide a head
        //  if cannot find, reverse all
        // from head to the end, final the smallest one > head
        // swap head and that one
        // recursive do the next --> can be optimize.. 
        helperPermu(nums, 0); 
    }
};
