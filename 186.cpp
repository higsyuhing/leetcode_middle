class Solution {
public:
    
    void helper_reverse(vector<char>& s, int l, int r){
        // reverse from [l, r) in s
        while(l < (r-1)){
            char tmp = s[l]; 
            s[l] = s[r-1]; 
            s[r-1] = tmp; 
            l++; 
            r--; 
        }
    }
    
    void reverseWords(vector<char>& s) {
        
        // reverse whole string
        helper_reverse(s, 0, s.size()); 
        
        // reverse each word
        int l, r; 
        l = 0; r = 1; 
        
        while(r < s.size()){
            if(s[r-1] == ' '){
                helper_reverse(s, l, r-1); 
                l = r; 
            }
            r++; 
        }
        
        helper_reverse(s, l, r); 
    }
};

/*

        
        
        int ls, le, rs, re, slen; 
        ls = 0; le = 1; 
        slen = s.size(); 
        re = s.size(); rs = re - 1; 
        char cl, cr, tmp; 
        
        while(le <= rs){
            //for(int i = 0; i < s.size(); i++) cout << s[i]; 
            //cout << endl; 
            
            cl = s[le-1]; 
            cr = s[rs]; 
            s[le-1] = cr; 
            s[rs] = cl; 
            
            if(cl == ' '){
                helper_reverse(s, slen - le + 1, slen - ls); 
                ls = le; 
            }
            
            if(cr == ' '){
                helper_reverse(s, slen - re, slen - rs - 1); 
                re = rs; 
            }
            
            le++; 
            rs--; 
        }
        
        //    for(int i = 0; i < s.size(); i++) cout << s[i]; 
        //    cout << endl; 
        
        //cout << s[rs] << " " << s[le-1] << " " << rs << " " << le << endl; 
                
        if(s[rs] == ' '){
            helper_reverse(s, slen - le + 1, slen - ls); 
        }
        if(s[le-1] == ' '){
            helper_reverse(s, slen - re, slen - rs - 1); 
        }
        if((s[rs] != ' ') && (s[le-1] != ' ')){
            helper_reverse(s, ls, re); 
        }
        
        //    for(int i = 0; i < s.size(); i++) cout << s[i]; 
        //    cout << endl; 
        

*/
