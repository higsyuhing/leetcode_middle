class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // create a hashmap, fill in the char that is the dominate of key
        // a set and a counter: set with all current key
        // generate the next level of set: put all hashmap value into it, counter++
        // repeat until the set is empty. 
        
        // hashmap: <string, vector<int>>: the index in words
        // de-duplicate: check if already in set.. 
        
        map<string, vector<int>> hash; 
        vector<int> temp; 
        for(int i = 0; i < words.size(); i++){
            // add yourself into hash, length is at least 1
            hash[words[i]] = temp; 
        }
        for(int i = 0; i < words.size(); i++){
            // check if predecessor is in hash
            string word = words[i]; 
            string tempstr; 
            for(int j = 0; j < word.size(); j++){
                tempstr = word.substr(0, j); 
                tempstr += word.substr(j+1); 
                if(hash.find(tempstr) != hash.end()){
                    hash[tempstr].push_back(i); 
                }
            }
        }
        
        int counter = 0; 
        int oddcurr = 1; 
        set<string> set1, set2; 
        set<string>* ptrcurr; 
        set<string>* ptrnext; 
        for(int i = 0; i < words.size(); i++){
            // init set with all words
            set1.insert(words[i]); 
        }
        while(1){            
            if(oddcurr){
                ptrcurr = &set1; 
                ptrnext = &set2; 
                oddcurr = 0; 
            }
            else{
                ptrcurr = &set2; 
                ptrnext = &set1; 
                oddcurr = 1; 
            }
            
            // check if set is empty
            if(ptrcurr->empty()) return counter; 
            
            // for each word in ptrcurr set, add it's corresponding dominate
            // to ptrnext set, if this word is not in ptrnext set
            for(auto iti = ptrcurr->begin(); iti != ptrcurr->end(); iti++){
                vector<int>& dominate = hash[*iti]; 
                for(auto itj = dominate.begin(); itj != dominate.end(); itj++){
                    if(ptrnext->find(words[*itj]) == ptrnext->end()){
                        ptrnext->insert(words[*itj]); 
                    }
                }
            }
            
            counter++; 
            ptrcurr->clear(); 
        }
        
    }
};

/*

// DP!! wow! 

class Solution {
public:
    static bool mySort(string &a, string &b){
        return a.length() < b.length();
    }
    bool helper(string &word1, string &word2) 
      {
    
        int i = 0;
        int j = 0;
          if(word1.size()+1!=word2.size())return 0;
      //   if(word2.size()+1!=word1.size())return 0;
        while (i < word1.length() && j < word2.length()) {
            if (word1[i] == word2[j]) {
                ++i;
            }
            ++j;
            if (j-i >1) {
                return false;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size()+1, 1);
        sort(words.begin(), words.end(), mySort);
        int mx = 1;
        for(int i =1; i < words.size(); i++){
            int maxVal = 0;
            for(int j = 0; j < i ; j++){
                if(helper(words[j], words[i])){
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i]= maxVal+1;
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};

*/


