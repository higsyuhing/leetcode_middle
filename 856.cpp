class Solution {
public:
    int scoreOfParentheses(string s) {
        // stack, like a calculator.. 
        // use '-1' to represent '(', since all numbers are positive
        stack<int> valstack; 

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                valstack.push(-1); 
            }
            else{
                int val = 0; 
                while (valstack.top() != -1){
                    val += valstack.top(); 
                    valstack.pop(); 
                }
                valstack.pop(); // -1
                val = (val == 0) ? 1 : (val*2); // if no num, '()' 1, else num*2
                valstack.push(val); 
            }
        }
        int res = 0; 
        while (!valstack.empty()){
            res += valstack.top(); 
            valstack.pop(); 
        }

        return res; 
    }
};

/*
(()(()()()))
(1 + (1+1+1) *2)*2

push
push
pop
-> push 1
push
push
pop
-> push 1
push
pop
-> push 1
push
pop
-> push 1
pop
<- pop 1, pop 1, pop 1
-> push 3*2
pop
<- pop 3*2, pop 1
-> push (1+3*2)*2
end: 
<- pop (1+3*2)*2

*/
