class Solution {
public:
    string reorganizeString(string S) {
        // hash and sort, {a:1, b:3, c:6, d:7 etc. }
        // failed scenario: if have only 2 sets
        //      set 1 inserting into middle, 
        //      set 2 is identical and as inserted set
        //      is size of set 1 < size of set 2 - 1, thus failed. 
        
        /*
        map<char, int> charmap; 
        for(int i = 0; i < S.size(); i++){
            if(charmap.find(S[i]) == charmap.end())
                charmap[S[i]] = 1; 
            else
                charmap[S[i]]++;
        }
        
        int maxcharnum = 0; 
        for(map<char, int>::iterator it = charmap.begin(); 
            it! = charmap.end(); ++it){
            if(it->second > maxcharnum) maxcharnum = it->second; 
        }
        
        if()
        */
        
        // except the last one, all interleaving from the left, 
        // the last one interleaving from the right.. 
        vector<pair<int, char>> charmap; 
        charmap.reserve(26); 
        for(int i = 0; i < 26; i++){
            charmap.push_back(make_pair(0, 'a'+i)); 
        }
        
        for(int i = 0; i < S.size(); i++){
            charmap[(int)(S[i]-'a')].first++; 
        }
        sort(charmap.begin(), charmap.end()); 
        
        string ret = ""; 
        string temp = ""; 
        for(int i = 0; i < 25; i++){
            if(charmap[i].first == 0) continue; 
            // use temp to merge the chars
            char currchar = charmap[i].second; 
            int k = 0; // index for ret
            for(int j = 0; j < charmap[i].first; j++){
                temp = temp + currchar; 
                if(k < ret.size()){
                    temp = temp + ret[k]; 
                    k++; 
                }
            }
            while(k < ret.size()){
                temp = temp + ret[k]; 
                k++; 
            }
            
            // move temp to ret, empty temp
            ret = temp; 
            temp = ""; 
        }
        
        // last has 3 char (aaa), ret has size 1 (b)
        if(charmap[25].first > (ret.size()+1)) return ""; 
        
        // the last one should be inserted in a reversed way
        char currchar = charmap[25].second; 
        int k = ret.size()-1; // index for ret
        for(int j = 0; j < charmap[25].first; j++){
            temp = temp + currchar; 
            if(k >= 0){
                temp = temp + ret[k]; 
                k--; 
            }
        }
        while(k >= 0){
            temp = temp + ret[k]; 
            k--; 
        }
        return temp; 
    }
};

/*
hmmmmm... using heap is faster.. for constructing the string
make judgement only requires the biggest one is larger than N/2
*/
