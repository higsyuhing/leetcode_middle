static auto x=[](){ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL;}();//speed I/O
class Solution {
public:
    //function to split array in two parts first part contains all numbers with given bit=0 and second part contains all the numbers with given bit=1, the function return start of the second part
    int partitionar(vector<int>&nums,int start,int end,int bit)
    {
        int part = start;
        int mask = 1<<bit;
        for(int i=start;i<=end;++i)
            if((nums[i]&mask)==0)
                swap(nums[i],nums[part++]);
        return part;
        
    }
    int helper(vector<int>&nums,int ls,int le,int rs,int re,int bit)
    {
        if(ls>le || rs>re)//edge cases
            return 0;
        if((ls==le && rs==re)||bit==-1)//when we have seen all the bits or when we have only one option to choose
           return nums[ls]^nums[rs];
        int part1 = partitionar(nums,ls,le,bit);//partition the first list
        int part2 = partitionar(nums,rs,re,bit);//partition the second list
        int ans=0;
        if(part1>ls && part1<=le)//the first list have both kind of numbers i.e with current bit set and unset
        {
            //taking the numbers int list 1 where current bit is 0.taking the numbers int list 2 where current bit is 1.
            if(part2>rs)
                ans=helper(nums,part1,le,rs,part2-1,bit-1);
            //taking the numbers int list 1 where current bit is 1.taking the numbers int list 2 where current bit is 0.
            if(part2<=re)
                ans=max(ans,helper(nums,ls,part1-1,part2,re,bit-1));
        }
        //All numbers in list 1 has current bit = 1
        else if(part1==ls)
        {
            if(part2>rs)//if list 2 has some numbers with current bit = 0 then we take those numbers.
                ans=helper(nums,part1,le,rs,part2-1,bit-1);
            else //else we have no option we cannot have the current bit set in the final answer.
                ans=helper(nums,ls,le,rs,re,bit-1);
        }
        else//All numbers in list 1 has current bit = 0
        {
            if(part2<=re)//if list 2 has some numbers with current bit = 1 then we take those numbers.
                ans=helper(nums,ls,le,part2,re,bit-1);
            else//else we have no option we cannot have the current bit set in the final answer.
                ans=helper(nums,ls,le,rs,re,bit-1);
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int bit = 31;
        int part=partitionar(nums,0,nums.size()-1,bit);
        //findind the first bit where we can actually partition our set if no such bit is found then we can say the complete contains copies of a particular number only hence ans is 0.
        while(part==0 || part>=nums.size())
        {
            --bit;
            part=partitionar(nums,0,nums.size()-1,bit);
        }
        if(bit<0)//No partition exists.
            return 0;
        else return helper(nums,0,part-1,part,nums.size()-1,bit-1);//partion exists so recurring.
    }
};
