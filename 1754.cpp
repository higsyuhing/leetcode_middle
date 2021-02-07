class Solution {
public:
    string largestMerge(string word1, string word2) {
        int curr1, curr2, len1, len2; 
        curr1 = 0; curr2 = 0; len1 = word1.size(); len2 = word2.size(); 
        string result = ""; 
        
        while((curr1 < len1) && (curr2 < len2)){
            if(word1[curr1] < word2[curr2]){
                result += word2[curr2]; 
                curr2++; 
                continue; 
            }
            else if(word1[curr1] > word2[curr2]){
                result += word1[curr1]; 
                curr1++; 
                continue; 
            }
            // equal case
            const char *cw1 = word1.c_str(); 
            const char *cw2 = word2.c_str(); 
            int res = strcmp(&cw1[curr1+1], &cw2[curr2+1]); 
            
            if(res < 0){
                result += word2[curr2]; 
                curr2++; 
                continue; 
            }
            else{
                result += word1[curr1]; 
                curr1++; 
                continue; 
            }
        }
        
        if(curr1 < len1){
            result += word1.substr(curr1); 
        }
        else if(curr2 < len2){
            result += word2.substr(curr2); 
        }
        
        return result; 
    }
};
