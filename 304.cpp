class NumMatrix {
public:
    vector<vector<int>> accu; // sum of rec from [0,0] to [i-1,j-1], exclude
    
    NumMatrix(vector<vector<int>>& matrix) {
        int rownum = matrix.size(); 
        if(rownum == 0) return; 
        int colnum = matrix[0].size(); 
        int i, j, k; 
        
        accu.reserve(rownum+1); 
        vector<int> temp; 
        temp.reserve(colnum+1); 
        accu.push_back(temp); 
        
        vector<int> rowsum; 
        rowsum.reserve(colnum); 
        
        for(j = 0; j < colnum; j++){
            accu[0].push_back(0); 
            rowsum.push_back(0); 
        }
        accu[0].push_back(0); 
        
        for(i = 0; i < rownum; i++){
            accu.push_back(temp); 
            accu[i+1].push_back(0); 
            for(j = 0; j < colnum; j++){
                accu[i+1].push_back(rowsum[j] + matrix[i][j]); 
                for(k = j; k < colnum; k++) rowsum[k] += matrix[i][j]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // use accumulation subtraction will be good! 
        // S = recrightbottom - (recleft + rectop - reclefttop)
        return (accu[row2+1][col2+1] - accu[row2+1][col1]
               - accu[row1][col2+1] + accu[row1][col1]); 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/*
I need fast vector allocation.. 

*/

