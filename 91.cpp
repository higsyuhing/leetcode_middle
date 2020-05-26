class Solution {
public:
    int numDecodings(string s) {
        // a DFS.. 
        // look ahead 2 digits, until the end, if not match, pop and take 1 digit. 
        // a stack for current digit position. if match the end, res++
        //stack<int> sindex;
        //int res = 0; 
        //int curr = 0; 
        
        // no.. it's a DP.. 
        // solution for n, then for n+1, you are in fact 2 cases: 
        //      n : 1 => you will have f(n) results
        //      n-1 : 2 => you will have f(n-1) results, if the last 2 is valid. 
        // init f(1) = 1
        
        // case: 202 -> 1, 20|2, thus should consider 0 for s[i]
        // case: 902 -> 0, since there is no way to handle 9,0, thus 0
        //          if any dp[i] is 0, return 0. 
        
        if(s.size() == 0) return 0; 
        if(s.size() == 1){
            if(s[0] == '0') return 0; 
            return 1; 
        }
        vector<int> dp; 
        dp.reserve(s.size()); 
        
        // init case
        if(s[0] == '0') return 0; 
        dp[0] = 1; 
        int res = 0; 
        if(s[1] != '0') res += 1; 
        if(s[0] == '1') res += 1; 
        if(s[0] == '2')
            if(s[1] < '7') res += 1; 
        if(res == 0) return 0; 
        dp[1] = res; 
        //cout << dp[0] << " " << dp[1] << endl; 
        
        for(int i = 2; i < s.size(); i++){
            res = 0; 
            
            // if not '0', consider all i-1
            if(s[i] != '0') res += dp[i-1]; 
            // if '0', not count
            
            // if 'xx1'|'x', thus have partition: 'xx'|'1x', always valid
            if(s[i-1] == '1'){
                res += dp[i-2]; 
            }
            // if 'xx2'|'c', thus have partition if 'c' is 0-6
            if(s[i-1] == '2'){
                if(s[i] < '7'){
                    res += dp[i-2]; 
                }
            }
            
            if(res == 0) return 0; // no way to partition here
            dp[i] = res; 
        }
        
        return dp[s.size()-1]; 
    }
};
