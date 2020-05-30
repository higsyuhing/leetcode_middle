class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n]; //dp[i][j] = 1, if s[i..j] is palindrome; else 0
        memset(dp, 0, sizeof(dp));
        
        //odd length palindromes
        for(int i = 0; i < n; i++){
            int j = i, k = i;
            while(j >= 0 && k < n && s[j]==s[k]){
                dp[j][k] = 1;
                j--; k++;
            }
        }
        //even length palindromes
        for(int i = 0; i + 1 < n; i++){
            int j = i, k = i + 1;
             while(j >= 0 && k < n && s[j]==s[k]){
                dp[j][k] = 1;
                j--; k++;
            }
        }
        
        int cnt = 0; 
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};
/*
- 2D dp..
- also not very sure about the solution 2 algorithm.. 
sol.py: 

def countSubstrings(self, S):
    def manachers(S):
        A = '@#' + '#'.join(S) + '#$'
        Z = [0] * len(A)
        center = right = 0
        for i in xrange(1, len(A) - 1):
            if i < right:
                Z[i] = min(right - i, Z[2 * center - i])
            while A[i + Z[i] + 1] == A[i - Z[i] - 1]:
                Z[i] += 1
            if i + Z[i] > right:
                center, right = i, i + Z[i]
        return Z

    return sum((v+1)/2 for v in manachers(S))

*/



/*
class Solution {
public:
    bool isPalindromic(string& s, int i, int j){
        // string s [i,j) is isPalindromic? 
        if(i >= j) return false; 
        int a, b; 
        for(a = i, b = j-1; a < b; a++, b--){
            if(s[a] != s[b]) return false; 
        }
        return true; 
    }
    
    int countSubstrings(string s) {
        // a DP? 
        // given n, for n+1 it will: 
        // itself, and all previous combinations.. 
        
        vector<int> dpboard; 
        dpboard.reserve(s.size()); 
        
        
        
        return 0; 
        
        
    }
};
*/
