class Solution {
public:
    int right2left(int n){
        if(n == 1) return 1; 
        if(n%2){ // odd
            return 2*left2right(n/2); 
        }
        else{ // even
            return 2*left2right(n/2)-1; 
        }
    }
    
    int left2right(int n){
        if(n == 1) return 1; 
        return 2*right2left(n/2); 
    }
    
    int lastRemaining(int n) {
        return left2right(n); 
    }
};
