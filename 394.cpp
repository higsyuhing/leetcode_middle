class Solution {
public:
    string decodeString(string s) {
        // recursive call.. no, I want to use stack, char stack, rep stack
        // 1. char, push
        // 2. number, collect until '[', 
        //      push int into rep stack, push [ into char stack
        // 3. meet ']', pop, until '[', construct a string
        //      pop rep stack, rep string, push
        // 4. end, pop all construct string, ret
        
        stack<string> charstack; 
        stack<int> repstack; 
        
        string temp, temp1; 
        int rep; 
        int state = 0; 
        // state table: 0: unset, 1: char, 2: number
        for(int i = 0; i < s.size(); i++){
            //cout << i << ": " << state << endl; 
            if((s[i] >= '0') && (s[i] <= '9')){
                if(state == 0){
                    rep = (int)(s[i] - '0'); 
                    state = 2; 
                }
                else if(state == 1){
                    charstack.push(temp); 
                    temp = ""; 
                    rep = (int)(s[i] - '0'); 
                    state = 2; 
                }
                else{ // state == 2
                    rep = rep*10 + (int)(s[i] - '0'); 
                }
            }
            else if(s[i] == '['){
                if(state != 2){
                    cout << "meet [ with non-rep prefix! " << endl; 
                    return ""; 
                }
                charstack.push("["); 
                repstack.push(rep); 
                state = 0; 
            }
            else if(s[i] == ']'){
                if(state == 2){
                    cout << "meet ] with rep prefix! " << endl; 
                    return ""; 
                }
                if(state != 1) temp = ""; // last chars.. 
                while(1){
                    temp1 = charstack.top(); 
                    if(temp1 != "["){
                        charstack.pop(); 
                        temp = temp1 + temp; 
                    }
                    else{ // "["
                        temp1 = ""; 
                        charstack.pop(); 
                        rep = repstack.top(); 
                        repstack.pop(); 
                        for(int j = 0; j < rep; j++){
                            temp1 = temp1 + temp; 
                        }
                        charstack.push(temp1); 
                        state = 0; 
                        temp = ""; 
                        break; 
                    }
                }
            }
            else{
                if(state == 2){
                    cout << "meet char with rep prefix! " << endl; 
                    return ""; 
                }
                else if(state == 0){
                    temp = s[i]; 
                    state = 1; 
                }
                else temp += s[i]; 
            }
        }
        
        if(state == 2){
            cout << "meet ] with rep prefix! " << endl; 
            return ""; 
        }
        if(state != 1) temp = ""; 
        while(charstack.size()){
            temp1 = charstack.top(); 
            charstack.pop(); 
            temp = temp1 + temp; 
        }
        return temp; 
    }
};
