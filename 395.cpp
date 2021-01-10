class Solution {
public:
    int longestSubstring(string s, int k) {
        // very naive O(n^2)
        unsigned distchar[26]; 
        int i, j, m, res, tmp, cmp, len; 
        res = 0; 
        len = s.size(); 
        
        for(i = 0; i < len; i++){
            for(m = 0; m < 26; m++) distchar[m] = 0; 
            for(j = i; j < len; j++){
                // from [i, j]
                // add j into dist
                distchar[(unsigned)(s[j] - 'a')]++; 
                // check if match.. 
                tmp = k; 
                for(m = 0; m < 26; m++){
                    cmp = (distchar[m] > 0) ? distchar[m] : k; 
                    tmp = (tmp > cmp) ? cmp : tmp; 
                }
                if(tmp == k){
                    res = (res < (j - i + 1)) ? (j - i + 1) : res; 
                }
            }
        }
        return res; 
    }
};

/*
sliding window solution is not easy.. 

*/


