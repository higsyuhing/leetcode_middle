class Solution {
public:
    string alphabetBoardPath(string target) {
        string ret = ""; 
        int currr, currc, lastr, lastc; 
        lastr = 0; lastc = 0; 

        // if target is 'z', then column first
        // other target, always row first
        for (int i = 0; i < target.size(); i++){
            char c = target[i]; 
            int offset = (int)(c - 'a'); 
            currr = offset / 5; 
            currc = offset % 5; 

            if (c == 'z'){
                // column first
                while (currc > lastc){
                    ret += "R"; 
                    lastc++; 
                }
                while (currc < lastc){
                    ret += "L"; 
                    lastc--; 
                }
                // then row
                while (currr > lastr){
                    ret += "D"; 
                    lastr++; 
                }
                while (currr < lastr){
                    ret += "U"; 
                    lastr--; 
                }
                ret += "!"; 
            }
            else{
                // row first
                while (currr > lastr){
                    ret += "D"; 
                    lastr++; 
                }
                while (currr < lastr){
                    ret += "U"; 
                    lastr--; 
                }

                // then column
                while (currc > lastc){
                    ret += "R"; 
                    lastc++; 
                }
                while (currc < lastc){
                    ret += "L"; 
                    lastc--; 
                }
                ret += "!"; 
            }

            // lastr, lastc == currr, currc
        }

        return ret; 
    }
};
