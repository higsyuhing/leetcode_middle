// typedef struct _pt_node {
//     bool isword; 
//     struct _pt_node *array[26]; // for each char, next node.. 
// } pt_node; 

// pt_node *pt_node_add(pt_node *curr, string& s, int pos){
//     if (curr == NULL)
// }


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // prefix tree.. 
        // no.. DP
        vector<bool> dp(s.size()+1, false); 
        dp[0] = true; // [, 0) is true
        unordered_set<string> dict; 
        for (string& word : wordDict){
            dict.insert(word); 
        }

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];

    }
};




