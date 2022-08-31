class Solution {
public:
    int numSplits(string s) {
        
        // notes: 
        //  not just collect the distinct letters: N and check when there is N/2
        //  e.g. abcd(aaa)abcd, any cut with in (a..a) is valid. 
        // need to use a histogram to collect the char distribution and 
        //  scan again to check if Set-letter-left == Set-letter-right
        // 2 steps: 
        // 1. scan through and get histogram
        // 2. maintain 2 counters and 1 set, scan again.. 
        //      keep the Set-letter-left, Set-letter-right and set in the left
        
        map<char, int> histo; 
        for (char c : s)
        {
            if (histo.count(c) == 0)
                histo[c] = 1; 
            else
                histo[c]++; 
        }
        
        int countleft, countright; 
        countleft = 0; 
        countright = histo.size(); 
        set<char> setleft; 
        
        int ret = 0; 
        for (char c : s)
        {
            if (countleft < countright)
            {
                // working on the left set
                if (setleft.count(c) == 0)
                {
                    setleft.insert(c); 
                    countleft++; 
                }
                // if already seen, no new move
                
                // working on the right set
                histo[c]--; 
                if (histo[c] == 0) countright--; 
            }
            else if (countleft == countright)
            {
                // at this point we can add ret. 
                ret++; 
                
                // check new char, left set
                if (setleft.count(c) == 0) break; 
                
                // right set
                histo[c]--; 
                if (histo[c] == 0) break; 
            }
        }
        
        return ret; 
    }
};
