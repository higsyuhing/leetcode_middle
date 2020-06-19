class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // ACGT can represented by 2 bits, thus 10 letter sequence is 20. 
        // can be represented via a int number.. 
        // thus a hashtable scaning through? 
        
        vector<string> ret; 
        if(s.size() < 10) return ret; 
        
        map<char, int> refhash; 
        refhash['A'] = 0; 
        refhash['C'] = 1; 
        refhash['G'] = 2; 
        refhash['T'] = 3; 
        
        // null -> (string, 0) for init -> (string, 1) for recorded
        map<int, int> strhash; 
        
        int tempstr = 0; 
        for(int i = 0; i < 9; i++){
            tempstr = tempstr << 2; 
            tempstr |= refhash[s[i]]; 
        }
        
        for(int i = 9; i < s.size(); i++){
            tempstr &= 0x3ffff; 
            tempstr = tempstr << 2; 
            tempstr |= refhash[s[i]]; 
            
            if(strhash.find(tempstr) == strhash.end()){
                strhash[tempstr] = 0; 
            }
            else if(strhash[tempstr] == 0){
                strhash[tempstr] = 1; 
                ret.push_back(s.substr(i-9, 10)); 
            }
        }
        
        return ret; 
        
    }
};
