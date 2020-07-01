class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        /*
        if(X == Y) return 0; 
        if(X > Y) return (X-Y); 
        
        // then I am guessing BFS?? 
        */
        
        // alright.. check the sol.. 
        int ans = 0; 
        while(Y > X){
            ans++; 
            if(Y%2) Y++; 
            else Y = Y >> 1; 
        }
        
        return (ans + X-Y); 
    }
};
