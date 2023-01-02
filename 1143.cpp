class Solution {
public:

    int dpcompute(vector<vector<int>>& dptable, string& text1, string& text2, int i, int j){
        if (i == text1.size() || j == text2.size())
            return 0; // no entry in dptable, string out of size
        
        if (dptable[i][j] != -1)
            return dptable[i][j]; // memorization
        
        if (text1[i] == text2[j]){
            int ret = dpcompute(dptable, text1, text2, i+1, j+1); 
            dptable[i][j] = ret+1; 
        }
        else{
            int left = dpcompute(dptable, text1, text2, i+1, j); 
            int right = dpcompute(dptable, text1, text2, i, j+1); 
            dptable[i][j] = (left > right) ? left : right; 
        }

        return dptable[i][j]; 
    }

    int longestCommonSubsequence(string text1, string text2) {
        // DP.. m*n table.. the element: table[i][j] means: 
        //  LCS for substring text1[i, end) and substring text2[j, end)

        vector<vector<int>> dptable; 
        dptable.reserve(text1.size()); 
        for (int i = 0; i < text1.size(); i++){
            vector<int> tmp(text2.size(), -1); 
            dptable.push_back(tmp); 
        }

        return dpcompute(dptable, text1, text2, 0, 0); 
    }
};


/*
// bottom-up dp is much faster

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(),n=text2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;++i) dp[i][0]=0;
        for(int i=0;i<=n;++i) dp[0][i]=0;
        for(int i=1;i<=m;++i) for(int j=1;j<=n;++j){
            if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[m][n];
    }
};
*/


