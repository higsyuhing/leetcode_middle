class Solution {
    public int[][] candyCrush(int[][] board) {
        boolean found = true;
        int m = board.length, n = board[0].length;
         
        while (found) {
            found = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 2; j++) {
                    int val = Math.abs(board[i][j]);
                    if (val != 0 && Math.abs(board[i][j + 1]) == val 
                       && Math.abs(board[i][j + 2]) == val) {
                         
                        board[i][j] = board[i][j + 1] = board[i][j + 2] = -val;
                        found = true;
                    }
                }
            }
             
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m - 2; j++) {
                    int val = Math.abs(board[j][i]);
                    if (val != 0 && Math.abs(board[j + 1][i]) == val 
                       && Math.abs(board[j + 2][i]) == val) {
                         
                        board[j][i] = board[j + 1][i] = board[j + 2][i] = -val;
                        found = true;
                    }
                }
            }
             
            for (int c = 0; c < n; ++c) {
                int wr = m - 1;
                for (int r = m-1; r >= 0; --r)
                    if (board[r][c] > 0)
                        board[wr--][c] = board[r][c];
                while (wr >= 0)
                    board[wr--][c] = 0;
            }
        }
         
        return board;
    }
     
     
}
