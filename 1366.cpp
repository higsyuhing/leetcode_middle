class Solution {
public:
    
    struct sort_pred {
        bool operator()(const std::pair<int,char> &left, const std::pair<int,char> &right) {
            return left.first > right.first;
        }
    };
    
    string helperRankPos(vector<string>& votes, set<char>& setCandidate, int pos){
        string ret = ""; 
        
        // if we reach the end of the vote, return with alphabetical order
        if (pos == votes[0].size()){
            for (auto it = setCandidate.begin(); it != setCandidate.end(); it++){
                ret += (*it); 
            }
            return ret; 
        }
        
        // we are in position: pos, we check all vites with setCandidate 
        // just use an array and sort them.. 
        
        int tmp_array[26]; // can use a hash map
        for (int i = 0; i < 26; i++) tmp_array[i] = 0; 
        
        for (auto& vote : votes){
            char c = vote[pos]; 
            if (setCandidate.count(c) != 0){
                tmp_array[(int)(c - 'A')]++; 
            }
        }
        
        // make pair in a vector and sort them.. 
        vector<pair<int, char> > vec; 
        for (char c : setCandidate){
            vec.push_back( make_pair(tmp_array[(int)(c - 'A')], c) ); 
        }
        
        sort(vec.begin(), vec.end(), sort_pred()); 
        
        // check if we need to go recursively.. 
        // set<char> nextCandidate; 
        int lastval = -1; 
        bool flagrec = false; 
        string tmp = ""; 
        
        for (pair<int, char>& p : vec){
            int val = p.first; 
            char c = p.second; 
            
            if (flagrec){
                // if we are in recursive check, that means some previous are equal
                if (lastval == val){
                    // the current one is also equal.. 
                    tmp += c; 
                    // continue; 
                }
                else{
                    // we are different.. handle the previous one.. 
                    set<char> nextCandidate; 
                    for (char tmpc : tmp){
                        nextCandidate.insert(tmpc); 
                    }
                    string tmpret = helperRankPos(votes, nextCandidate, pos+1); 
                    ret += tmpret; 
                    // clear the structure
                    flagrec = false; 
                    
                    // put the current one
                    lastval = val; 
                    tmp = c; 
                    // continue; 
                }
            }
            else{
                // we are not in a recursive check. check val also. 
                if (lastval == val){
                    // we fall into a recursive check. 
                    flagrec = true; 
                    tmp += c; 
                    // continue; 
                }
                else{
                    // we keep the previous one in the ret. 
                    ret += tmp; 
                    // put the current one
                    lastval = val; 
                    tmp = c; 
                    // continue; 
                }
            }
            
        }
        
        // some of them are in the tmp. 
        if (flagrec){
            // we are different.. handle the previous one.. 
            set<char> nextCandidate; 
            for (char tmpc : tmp){
                nextCandidate.insert(tmpc); 
            }
            string tmpret = helperRankPos(votes, nextCandidate, pos+1); 
            ret += tmpret; 
        }
        else{
            ret += tmp; 
        }
        
        return ret; 
    }
    
    string rankTeams(vector<string>& votes) {
        
        // if we can resolve in the i-th position, 
        // then the remaining positions are not important. 
        
        // use recursive calls with priority queue
        // use set for the candidate in the current position
        
        set<char> setCandidate; 
        for (char c : votes[0]){
            setCandidate.insert(c); 
        }
        
        string ret = helperRankPos(votes, setCandidate, 0); 
        
        return ret; 
    }
};
