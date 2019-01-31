class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //we use a sorted string as the hash key, ascii order
        map<string, vector<string>> hashmap; 
        vector<vector<string>> result; 
        
        /*
        //test program for map usage
        string str1("hello"); 
        string str2("hello"); 
        
        if(str1 == str2) printf("Yes\n");
        else printf("No\n");
        
        vector<string> unit; 
        hashmap.insert({str1, unit});
        
        if(hashmap.find(str2) == hashmap.end()) printf("No\n");
        else printf("Yes\n");
        
        //Yes & Yes as a result
        */
        
        int histogram[26]; 
        char curr; 
        for(auto it1 = strs.begin(); it1 != strs.end(); ++it1){
            //init
            string tempstr(*it1);
            string hashkey(""); 
            for(int i = 0; i < 26; i++) histogram[i] = 0; 
            
            //gen hashkey
            for(auto it2 = tempstr.begin(); it2 != tempstr.end(); ++it2){
                curr = *it2; 
                unsigned index = (unsigned)(curr - 'a'); 
                histogram[index]++; 
            }
            for(int i = 0; i < 26; i++) hashkey.append(histogram[i], 'a' + i); 
            
            //check hashmap and operate
            auto fit = hashmap.find(hashkey); 
            if(fit == hashmap.end()){
                vector<string> tempvec(1, tempstr); 
                hashmap.insert({hashkey, tempvec});
            }
            else{
                fit->second.push_back(tempstr); 
            }
        }
        
        /*
        //verify correctness
        for(auto it1 = hashmap.begin(); it1 != hashmap.end(); ++it1){
            cout << (it1->first) << endl; 
            vector<string> tempvec = it1->second; 
            for(auto it2 = tempvec.begin(); it2 != tempvec.end(); ++it2){
                cout << "   " << *it2 << endl; 
            }
        }
        */
        
        for(auto it1 = hashmap.begin(); it1 != hashmap.end(); ++it1){
            result.push_back(it1->second); 
        }
        
        return result; 
    }
};


/* sorting not hashing is also fine, I mean the [26] array */
