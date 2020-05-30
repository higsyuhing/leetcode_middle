class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // DFS.. 
        // try 3 digits, 2 digits, 1 digits.. 
        // longest: 111:111:111:111, shortest: 1:1:1:1
        
        // learned: 
        // 1. .size() return a size_t, it cannot handle <0 case
        // 2. check all possible cases: 001:10 etc.. 
        // 3. stoi() has out of range error. 
        
        vector<string> res; 
        int i, j, k; 
        
        //cout << "size s: " << s.size() << endl; 
        // lazy, using 4 loops..
        for(i = 3; i > 0; i--){
            // the first part of string
            if(((int)s.size() - i) < 3) continue; // remaining should be enough
            string str1 = s.substr(0, i); 
            if((i == 3) && (stoi(str1) > 255)) continue; 
            // now str1 is valid. str2 start at [i]
            //cout << i << ":" << str1 << endl; 
            if((i > 1) && (str1[0] == '0')) continue; 
            
            for(j = 3; j > 0; j--){
                if(((int)s.size() - i - j) < 2) continue; 
                string str2 = s.substr(i, j); 
                if((j == 3) && (stoi(str2) > 255)) continue; 
                // now str2 is valid. str3 start at [i+j]
                //cout << j << ":" << str2 << endl; 
                if((j > 1) && (str2[0] == '0')) continue; 
                
                for(k = 3; k > 0; k--){
                    if(((int)s.size() - i - j - k) < 1) continue; 
                    //cout << "check: " << (s.size() - i - j - k) << endl; 
                    string str3 = s.substr(i + j, k); 
                    if((k == 3) && (stoi(str3) > 255)) continue; 
                    // now str3 is valid. str4 start at [i+j+k]
                    //cout << k << ":" << str3 << endl; 
                    if((k > 1) && (str3[0] == '0')) continue; 
                    
                    if(((int)s.size() - i - j - k) > 3) continue; 
                    string str4 = s.substr(i + j + k); 
                    if(stoi(str4) > 255) continue; // if >3 nums, must be this case
                    //cout << str4 << endl; 
                    if(((str4.size()) > 1) && (str4[0] == '0')) continue; 
                    
                    res.push_back(str1+"."+str2+"."+str3+"."+str4); 
                }
            }
        }
        
        return res; 
    }
};
