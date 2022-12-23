class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calval; 
        for (string& s : tokens){
            if ((s[0] >= '0' && s[0] <= '9') || (s[0] == '-' && s.size() > 1)){
                // number
                int val = stoi(s); 
                calval.push(val); 
            }
            else{
                int val2 = calval.top(); calval.pop(); 
                int val1 = calval.top(); calval.pop(); 
                int val = 0; 
                if (s == "+"){
                    val = val1 + val2; 
                }
                else if (s == "-"){
                    val = val1 - val2; 
                }
                else if (s == "*"){
                    val = val1 * val2; 
                }
                else if (s == "/"){
                    val = val1 / val2; 
                }
                else{
                    cout << "op default?: " << s << endl; 
                }
                calval.push(val); 
            }
        }
        return calval.top(); 
    }
};
