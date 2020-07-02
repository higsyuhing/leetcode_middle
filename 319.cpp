class Solution {
public:
    int bulbSwitch(int n) {
        //the ith bulb remains on if i has odd factors.
        //out of all numbers only perfect squares have odd factors
        //so return count of all perfect squares <=n
        int count =0;
        for(int i=1;i*i<=n;i++){
            count++;
        }
        return count;
    }
};
