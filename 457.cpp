class Solution {
public:
    int getnext(vector<int>&nums,int index)
    {
        return (index+nums[index]+nums.size())%(nums.size());
    }

    bool circularArrayLoop(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            if(nums[i]==0) continue; 
            int slow=i;int fast=i;
            while(nums[slow]*nums[getnext(nums,slow)]>0&&
                 nums[fast]*nums[getnext(nums,fast)]>0&&
                 nums[fast]*nums[getnext(nums,getnext(nums,fast))]>0)
            {
                slow=getnext(nums,slow);
                fast=getnext(nums,getnext(nums,fast));

                if(slow==fast)//Means the cycle is detected
                {
                    if(slow==getnext(nums,slow))//Means cycle length is 1
                        break;
                    return true;
                }
            }
            slow=i;
            int val=nums[slow];
            while(val*nums[slow]>0)
            {
                int x=slow;
                slow=getnext(nums,slow);
                nums[x]=0;
            }
        }
        return false;   
    }
    
/*
// thus one direction will only access once if in a loop. (since no backward)
// this will make it much easier.. also maintain a cycle length. 
// why I feel that there is a much easier solution.. 

*/
};
