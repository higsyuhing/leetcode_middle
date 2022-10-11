class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // we can use a hashmap + window with size k.. 
        // but I am thinking if we can do better.. 
        
        set<string> hashset; 
        if (s.size() < k)
            return false; 
        
        for (int i = 0; i <= (s.size() - k); i++){
            string subs = s.substr(i, k); 
            if (hashset.find(subs) == hashset.end())
                hashset.insert(subs); 
        }
        
        // for (auto ele : hashset){
        //     cout << ele << endl; 
        // }
        
        if (hashset.size() == (1 << k))
            return true; 
        return false; 
    }
};

/*

a better solution: 

class Solution {
    public static boolean hasAllCodes(String s, int k) {
        int need = 1 << k;
        boolean[] got = new boolean[need];
        int allOne = need - 1;
        int hashVal = 0;

        for (int i = 0; i < s.length(); i++) {
            // calculate hash for s.substr(i-k+1,i+1)
            hashVal = ((hashVal << 1) & allOne) | (s.charAt(i) - '0');
            // hash only available when i-k+1 > 0
            if (i >= k - 1 && !got[hashVal]) {
                got[hashVal] = true;
                need--;
                if (need == 0) {
                    return true;
                }
            }
        }
        return false;
    }
}
*/
