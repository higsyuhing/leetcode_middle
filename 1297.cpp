class Solution {
    
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int sz = s.size(), uc = 0, res = 0;
        
        int t[26];
        memset(t, 0, sizeof(t));
        
        unordered_map<string, int> m;
        
        for (int i=0; i<=sz; i++) {
            if (i < minSize) {
                if (t[s[i]-'a']++ == 0) uc++;
            }else {
                if (uc <= maxLetters) m[s.substr(i-minSize, minSize)]++;
                
                if (i >= sz) break;

                if (--t[s[i-minSize]-'a'] == 0) uc--;

                if (++t[s[i]-'a'] == 1) uc++;
            }
        }
        
        for (auto const& f : m) res = max(res, f.second);
        
        return res;
        
    }
};

/*
I don't like this question. 

*/
