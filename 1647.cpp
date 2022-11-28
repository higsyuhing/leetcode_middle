class Solution {
public:
    int minDeletions(string s) {
        // collect histogram, then sort in dec order. 
        // maintain curr level = last.occurrence, then compare and substract. 

        int histo[26]; 
        for (int i = 0; i < 26; i++) histo[i] = 0; 
        for (char c : s){
            histo[(int)(c - 'a')]++; 
        }
        vector<int> array; 
        for (int i = 0; i < 26; i++){
            if (histo[i] > 0)
                array.push_back(histo[i]); // we don't care the char
        }
        if (array.size() <= 1) return 0; 
        sort(array.begin(), array.end()); 

        int res = 0; 
        int len = array.size(); 
        int level = array[len-1]; 
        for (int i = len-2; i >= 0; i--){
            // cout << level << ", " << res << endl; 
            int curr = array[i]; 
            if (level == 0){
                res += curr; 
                continue; 
            }
            if (curr < level){
                level = curr; 
            }
            else{
                // if (curr == level){
                //     level--; // curr = curr-1; level = curr
                //     res++; 
                // }
                // else{ // curr > level > 0
                //     level--; // curr = level-1; level = curr
                //     res += (curr - level + 1); 
                // }
                res += (curr - level + 1); 
                level--; 
            }
        }

        return res; 
    }
};
