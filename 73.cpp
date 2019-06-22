class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // the second way: 1. detect which row/col need to set 0, 2. set 0
        // it requires m+n space for keeping which row/col info
        int i, j, leni, lenj; 
        leni = matrix.size(); 
        if(leni == 0) return; 
        lenj = matrix[0].size(); 
        if(lenj == 0) return; 
        
        int *rowinfo = new int[leni]; 
        int *colinfo = new int[lenj]; 
        for(i = 0; i < leni; i++) rowinfo[i] = 0; 
        for(j = 0; j < lenj; j++) colinfo[j] = 0; 
        
        for(i = 0; i < leni; i++){
            for(j = 0; j < lenj; j++){
                if(matrix[i][j] == 0){
                    rowinfo[i] = 1; 
                    colinfo[j] = 1; 
                }
            }
        }
        
        for(i = 0; i < leni; i++){
            if(rowinfo[i] == 1){
                for(j = 0; j < lenj; j++) matrix[i][j] = 0; 
            }
        }
        for(j = 0; j < lenj; j++){
            if(colinfo[j] == 1){
                for(i = 0; i < leni; i++) matrix[i][j] = 0; 
            }
        }
        
        /*
        // see the hint, use the first row/col as the flag (if 0, set 0)
        // !! however, this is stupid and wasting brain.. 
        int i, j, leni, lenj, temp; 
        temp = matrix[0][0]; 
        leni = matrix.size(); 
        if(leni == 0) return; 
        lenj = matrix[0].size(); 
        if(lenj == 0) return; 
        
        for(i = 0; i < leni; i++){
            for(j = 0; j < lenj; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0; 
                }
            }
        }
        
        for(i = 1; i < leni; i++){
            if(matrix[i][0] == 0){
                for(j = 1; j < lenj; j++) matrix[i][j] = 0; 
            }
        }
        for(j = 1; j < lenj; j++){
            if(matrix[0][j] == 0){
                for(i = 1; i < leni; i++) matrix[i][j] = 0; 
            }
        }
        if(temp == 0){
            for(j = 1; j < lenj; j++) matrix[0][j] = 0; 
            for(i = 1; i < leni; i++) matrix[i][0] = 0; 
        }
        */
        
    }
};
