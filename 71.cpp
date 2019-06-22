class Solution {
public:
    string simplifyPath(string path) {
        // use a stack.. 
        vector<string> stack; 
        
        char *cpath = new char[path.length() + 1]; 
        char *temptoken = new char[path.length() + 1]; 
        strcpy(cpath, path.c_str());
        
        int clen = path.length(); 
        int startpos, currpos, tokenpos; 
        startpos = 0; currpos = 0; tokenpos = 0; 
        
        // parse
        while(1){
            // detect the end of one token
            if(cpath[currpos] == '/' || cpath[currpos] == '\0'){
                
                temptoken[tokenpos] = '\0'; 
                
                if(strcmp(temptoken, "..") == 0){
                    if(!stack.empty()) stack.pop_back(); 
                }
                else if((strcmp(temptoken, ".") != 0) && (strcmp(temptoken, "") != 0)){
                    // have content, ignore "." and "" (empty)
                    string token(temptoken); 
                    stack.push_back(token); 
                }
                
                // clean up and ready for the next token
                if(cpath[currpos] == '\0') break; 
                
                currpos++; 
                //startpos = currpos; 
                tokenpos = 0; 
            }
            // in the middle of one token
            else{
                temptoken[tokenpos] = cpath[currpos]; 
                currpos++; 
                tokenpos++; 
            }
        }
        
        // path-gen
        string res(""); 
        for(currpos = 0; currpos < stack.size(); currpos++){
            res += "/";
            res += stack[currpos]; 
        }
        if(stack.size() == 0) res += "/"; 
        
        return res; 
    }
};
