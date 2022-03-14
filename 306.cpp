class Solution {
public:
    uint64_t helper_convert(string& num, int s, int e){
        // get number value from [s, e)
        uint64_t val = 0; 
        for(int i = s; i < e; i++){
            val *= 10; 
            val += (uint64_t(num[i] - '0')); 
        }
        return val; 
    }
    
    bool helper_check(string& num, int s, uint64_t valf, uint64_t vals){
        // s: beginning index of the next val
        uint64_t expect = valf + vals; 
        uint64_t next = expect; 
        
        if(expect == 0){
            for(int i = s; i < num.size(); i++){
                if(num[i] != '0') return false; 
            }
            return true; 
        }
        
        stack<char> stackexp; 
        char last; 
        while(expect > 0){
            last = '0' + expect%10; 
            stackexp.push(last); 
            expect = expect/10; 
        }
        
        if((s + stackexp.size()) > num.size()) return false; 
        
        while(!stackexp.empty()){
            last = stackexp.top(); 
            stackexp.pop(); 
            
            if(last != num[s]) return false; 
            s++; 
        }
        
        if(s == num.size()) return true; 
        return helper_check(num, s, vals, next); 
    }
    
    bool isAdditiveNumber(string num) {
        
        if(num.size() < 3) return false; 
        
        // give the first 2 divide, then we can check if we research the end. 
        int fr, sr; // first right, second right, means [i - 1, i)
        uint64_t valf, vals; // first/second value
        
        for(fr = 1; fr < (num.size()-1); fr++){
            // jump if 0X
            if((num[0] == '0') && (fr > 1)) continue; 
            
            // valf: num [0, fr)
            valf = helper_convert(num, 0, fr); 
            
            for(sr = fr+1; sr < num.size(); sr++){
                // jump if 0X
                if((num[fr] == '0') && ((sr-fr) > 1)) continue; 
                
                // vals: num [fr, sr)
                vals = helper_convert(num, fr, sr); 
                
                // check the remaining string.. 
                if(helper_check(num, sr, valf, vals)) return true; 
            }
        }
        
        return false; 
    }
};
