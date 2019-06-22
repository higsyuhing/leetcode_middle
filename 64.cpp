class Solution {
public:
    int helpfunc(vector<vector<int>>& grid, int *val, int x, int y, int leny){
        // guaranteed valid x, y
        int temp, index; 
        index = x*leny+y; 
        if(val[index] != -1) return val[index]; 
        
        if((x == 0) && (y == 0)){
            val[0] = grid[0][0]; 
            return val[0]; 
        }
        if(x == 0){ // y must > 0
            temp = grid[x][y] + helpfunc(grid, val, x, y-1, leny); 
            val[index] = temp; 
            return temp; 
        }
        if(y == 0){ // x must > 0
            temp = grid[x][y] + helpfunc(grid, val, x-1, y, leny); 
            val[index] = temp; 
            return temp; 
        }
        
        int temp1 = helpfunc(grid, val, x-1, y, leny); 
        temp = helpfunc(grid, val, x, y-1, leny); 
        //cout << x <<" " << y << " " << temp1 << " " << temp << endl; 
        if(temp1 < temp) temp = temp1; 
        val[index] = grid[x][y] + temp; 
        return val[index]; 
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        // should be very classical DP problem
        
        int x, y, lenx, leny; 
        lenx = grid.size(); 
        if(lenx == 0) return 0; 
        leny = grid[0].size(); 
        if(leny == 0) return 0; 
        
        int *val = new int[lenx*leny]; 
        for(x = 0; x < (lenx*leny); x++) val[x] = -1; 
        
        int res = helpfunc(grid, val, lenx-1, leny-1, leny); 
        
        //for(x = 0; x < (lenx*leny); x++) cout << val[x] << " "; 
        //cout << endl; 
        
        
        return res; 
    }
};
