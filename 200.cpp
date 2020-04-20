class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row, col, res; 
        row = grid.size(); 
        if(row == 0) return 0; 
        col = grid[0].size(); 
        res = 0; 
        
        int i, j, tempi, tempj; 
        vector<int> srow; 
        vector<int> scol; 
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                
                if(grid[i][j] == '1'){
                    res++; 
                    srow.push_back(i); 
                    scol.push_back(j); 
                    while(srow.size() > 0){
                        tempi = srow[srow.size()-1]; 
                        tempj = scol[srow.size()-1]; 
                        srow.pop_back(); 
                        scol.pop_back(); 

                        if(tempi < 0) continue; 
                        if(tempi == row) continue; 
                        if(tempj < 0) continue; 
                        if(tempj == col) continue; 

                        if(grid[tempi][tempj] == '0') continue; 
                        if(grid[tempi][tempj] == '2') continue; 

                        // equals to 1
                        srow.push_back(tempi-1); 
                        scol.push_back(tempj); 
                        srow.push_back(tempi+1); 
                        scol.push_back(tempj); 
                        srow.push_back(tempi); 
                        scol.push_back(tempj-1); 
                        srow.push_back(tempi); 
                        scol.push_back(tempj+1); 
                        grid[tempi][tempj] = '2'; 
                    }
                }
                
            }
        }
        
        return res; 
    }
};
