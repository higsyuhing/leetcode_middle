class Solution {
public:
    int minFlips(int a, int b, int c) {
        // this one is easy? 
        // count number of 0/1s in a, b, c, then check the distance.. 
        // a, b: +, c: -
        
        // create a table: 
            // 0 0 0 : 0 : 0
            // 0 0 1 :-1 : 1
            // 0 1 0 : 1 : 1
            // 0 1 1 : 0 : 0
            // 1 0 0 : 1 : 1
            // 1 0 1 : 0 : 0
            // 1 1 0 : 2 : 2
            // 1 1 1 : 1 : 0
        int ref[8] = {0,1,1,0,1,0,2,0}; 
        
        int i, ret, temp; 
        ret = 0; 
        for(i = 0; i < 32; i++){
            temp = ((a & 1) << 2) + ((b & 1) << 1) + (c & 1); 
            //cout << temp << endl; 
            ret += ref[temp]; 
            a = a >> 1; b = b >> 1; c = c >> 1; 
        }
        return ret; 
        
    }
};
