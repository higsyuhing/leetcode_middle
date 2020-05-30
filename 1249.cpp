class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack with pair. <'('')', pos>
        
        stack<pair<char, int>> sstack; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                sstack.push(make_pair('(', i));
            }
            else if(s[i] == ')'){
                if(sstack.empty())
                    sstack.push(make_pair(')', i));
                else if(sstack.top().first == '(')
                    sstack.pop(); 
                else
                    sstack.push(make_pair(')', i));
            }
        }
        
        // note that the order in stack is in-ordered. 
        while(!sstack.empty()){
            s.erase(sstack.top().second, 1); 
            sstack.pop(); 
        }
        return s; 
    }
};
