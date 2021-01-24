class Solution {
public:
    int minCharacters(string a, string b) {
        int histoa[26] = {0}; 
        int histob[26] = {0}; 
        
        for(int i = 0; i < a.size(); i++){
            histoa[a[i] - 'a']++; 
        }
        for(int i = 0; i < b.size(); i++){
            histob[b[i] - 'a']++; 
        }
        
        // check case 1, 2
        int lengtha = a.size(); 
        int lengthb = b.size(); 
        int presuma = 0; 
        int presumb = 0; 
        int malmbr, marmbl; // move a left/right, move b right/left
        malmbr = lengtha + lengthb; 
        marmbl = malmbr; 
        
        for(int i = 0; i < 25; i++){
            // compute presum
            presuma += histoa[i]; 
            presumb += histob[i]; 
            
            int temp_malmbr = lengtha - presuma + presumb; 
            int temp_marmbl = presuma + lengthb - presumb; 
            
            malmbr = (malmbr > temp_malmbr) ? temp_malmbr : malmbr; 
            marmbl = (marmbl > temp_marmbl) ? temp_marmbl : marmbl; 
        }
        // keep the minimum of malmbr, marmbl
        
        // check case 3
        int mo = lengtha + lengthb; // move others
        for(int i = 0; i < 26; i++){
            int temp_mo = histoa[i] + histob[i]; 
            temp_mo = lengtha + lengthb - temp_mo; 
            
            mo = (mo > temp_mo) ? temp_mo : mo; 
        }
        
        // return res
        int res = (malmbr > marmbl) ? marmbl : malmbr; 
        res = (res > mo) ? mo : res; 
        
        return res; 
    }
};
