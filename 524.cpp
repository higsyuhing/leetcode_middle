class Solution {
public:

    // check: test is a substring of s: 
    //  test = s.delete-some-chars
    bool isSubString(string &s, string &test){
        int i, j; 
        i = 0; j = 0; // s[i] test[j]
        while (1){
            if ((s.size() - i) < (test.size() - j)) return false; 

            if (i == s.size() || j == test.size()) break; 

            if (s[i] == test[j]){
                i++; j++; 
            }
            else{
                i++; 
            }
        }
        if (j == test.size()) return true; 
        else return false; 
    }

    // compare 2 string s and t: return true if s is better than t: 
    // 1) s is longer, 2) same length but s is lexicographical smaller
    bool compare2str(string &s, string &t){
        if (s.size() > t.size()) return true; 
        else if (s.size() < t.size()) return false; 
        for (int i = 0; i < s.size(); i++){
            if (s[i] != t[i]){
                if (s[i] > t[i]) return false; 
                else return true; 
            }
        }
        return true; 
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ret; 
        for (auto &test : dictionary){
            if (isSubString(s, test) == true){
                if (compare2str(ret, test) == false){
                    ret = test; 
                }
            }
        }
        return ret; 
    }
};
