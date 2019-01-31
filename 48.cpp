class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        //printf("size: %d\n", n);
        
        int temp, indexi, indexj; 
        int target, indexti, indextj; 
        //if n is even, i,j will be all n/2
        //otherwise, i is n/2, j is n/2+1
        int jmax; 
        if(n%2 == 0) jmax = n/2; 
        else jmax = n/2+1; 

        for(int i = 0; i < (n/2); i++){
            for(int j = 0; j < jmax; j++){
                indexi = i; 
                indexj = j; 
                temp = matrix[indexi][indexj]; 
                for(int k = 0; k < 4; k++){
                    //printf("# %d, %d, %d\n", indexi, indexj, temp);
                    
                    //calculate
                    indexti = indexj; 
                    indextj = n - 1 - indexi; 
                    target = matrix[indexti][indextj]; 
                    matrix[indexti][indextj] = temp; 
                    //update
                    indexi = indexti; 
                    indexj = indextj; 
                    temp = target; 
                }
            }
        }
        
        
    }
};
