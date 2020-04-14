class Solution {
public:
    
    static bool indexvalid(int i, int j, int row, int col){
        if(i < 0) return false; 
        if(j < 0) return false; 
        if(i == row) return false; 
        if(j == col) return false; 
        return true; 
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        // use other number to represent all information
        // 0 death(d2d), 1 live(l2d); 2 d2l, 3 l2l
        // new value is the bit representation of new|old bit
        
        int i, j, row, col, neighbor; 
        row = board.size(); 
        col = board[0].size(); 
        
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                neighbor = 0; 
                if(indexvalid(i-1, j-1, row, col)) neighbor += (board[i-1][j-1] & 1); 
                if(indexvalid(i-1, j, row, col)) neighbor += (board[i-1][j] & 1); 
                if(indexvalid(i-1, j+1, row, col)) neighbor += (board[i-1][j+1] & 1); 
                if(indexvalid(i, j-1, row, col)) neighbor += (board[i][j-1] & 1); 
                if(indexvalid(i, j+1, row, col)) neighbor += (board[i][j+1] & 1); 
                if(indexvalid(i+1, j-1, row, col)) neighbor += (board[i+1][j-1] & 1); 
                if(indexvalid(i+1, j, row, col)) neighbor += (board[i+1][j] & 1); 
                if(indexvalid(i+1, j+1, row, col)) neighbor += (board[i+1][j+1] & 1); 
                
                // only consider x2l case
                if((neighbor == 2) && (board[i][j] == 1)) board[i][j] = 3; 
                if(neighbor == 3) board[i][j] += 2; 
            }
        }
        
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                board[i][j] = board[i][j] >> 1; 
            }
        }
        
    }
};
