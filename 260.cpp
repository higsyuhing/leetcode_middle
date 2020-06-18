class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // using XOR, can get a xor b in each bit
        // using counting and dividing 2 => each bit are same/diff
        
        int x=0;
        for(auto it:nums)
            x^=it;
        int idx;
        for(idx=0;idx<32;idx++)
            if(((x>>idx) & 1)!=0)break;
        int first=0;
        for(auto it:nums)
            if(((it>>idx)&1)!=0)
                first^=it;
        int second=x^first;
        return vector<int>{first,second};
    }
};


/*
I understand it.. fxxk u! 
for xor result, the first one with 1, (*)
it must contain the different one and many same pairs
thus xor again you can get the answer.. 
since two remaining numbers are different, this "1" guaranteed existed
*/

/*
0 0 1
0 1 0 *
0 0 1
0 1 1 *
0 1 0 *
1 0 1
xor
1 1 0 *

0 0/1 0/1
1 1/0 0/1


*/
