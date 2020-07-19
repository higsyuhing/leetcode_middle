class Solution {
public:
    int numTilings(int N) {
        // dp with memory about: 
        // dp[i] =  dp[i-1]   // need add X|X only way
        //        + dp[i-2]   // add XX|YY only way, note that XY|XY is counted in 
        //                          dp[i-1]
        //        + dp[i-3]+1 // all domino related one is covered in ...
        //// no. consider the following case: 
        // XXYY or XXBBDDE
        // XZZY    XAACCEE
        
        /*
        I am almost there! 
        https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1%2Bdpn-3
        */
        int md=1e9;
        md+=7;
        vector<long long> v(1001,0);
        v[1]=1;
        v[2]=2;
        v[3]=5;
        if(N<=3)
            return v[N];
        for(int i=4;i<=N;++i){
            v[i]=2*v[i-1]+v[i-3]; 
            v[i]%=md;
        }
        return v[N];
        
    }
};
