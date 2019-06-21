class Solution {
public:
    int uniquePaths(int m, int n) {
        // combination: from (m-1)+(n-1) to get (n-1) or (m-1)
        long unsigned index, up, down, res; 
        if(m > n){
            // use n-1
            res = 1; 
            for(index = 0; index < (n-1); index++){
                up = ((m-1)+(n-1) -index); 
                down = (1+index); 
                res = (res*up)/down; 
            }
            return (int)res; 
        }
        else{
            // use m-1
            res = 1; 
            for(index = 0; index < (m-1); index++){
                up = ((m-1)+(n-1) -index); 
                down = (1+index); 
                res = (res*up)/down; 
            }
            return (int)res; 
        }
        
    }
};
