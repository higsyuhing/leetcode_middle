class Solution {
public:
    
    /*
    int helpfunc(vector<vector<int>>& obstacleGrid, int x, int y, int lenx, int leny){
        if((x == lenx) || (y == leny)) return 0; 
        if(obstacleGrid[x][y] == 1) return 0; 
        if((x == (lenx-1)) && (y == (leny-1))) return 1; 
        
        return helpfunc(obstacleGrid, x+1, y, lenx, leny) + helpfunc(obstacleGrid, x, y+1, lenx, leny);
    }
    */
    
    int helpfunc1(vector<vector<int>>& obstacleGrid, int **mat, int x, int y){
        // no boundary
        if(x < 0 || y < 0) return 0; 
        
        // label 2 in obstacleGrid for having visited! 
        if(obstacleGrid[x][y] > 1) return mat[x][y]; 
        
        // if label 1, means obstacle, label and return
        if(obstacleGrid[x][y] == 1){
            obstacleGrid[x][y] = 3; // has visited
            mat[x][y] = 0; // no one comes here
            return 0; 
        }
        
        // if [0][0], then set 1
        if(x == 0 && y == 0){
            obstacleGrid[x][y] = 2; 
            mat[x][y] = 1; 
            return 1; 
        }
        
        int ret = helpfunc1(obstacleGrid, mat, x-1, y) + helpfunc1(obstacleGrid, mat, x, y-1); 
        obstacleGrid[x][y] = 2; 
        mat[x][y] = ret; 
        return ret; 
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        /*
        return helpfunc(obstacleGrid, 0, 0, obstacleGrid.size(), obstacleGrid[0].size()); 
        */
        
        // after checking hints, this is a DP problem.. 
        // that's why forwarding will waste lots of computation.. 
        
        int i, j, leni, lenj; 
        leni = obstacleGrid.size(); 
        lenj = obstacleGrid[0].size(); 
        int **mat = new int*[leni]; 
        for(i = 0; i < leni; i++){
            mat[i] = new int[lenj]; 
            for(j = 0; j < lenj; j++) mat[i][j] = 0; 
        }
        
        return helpfunc1(obstacleGrid, mat, leni-1, lenj-1); 
        
    }
};
