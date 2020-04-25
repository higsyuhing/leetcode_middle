class Solution {
public:
    
    // this is defeinitely a great answer I have seen
    // several usage I need to learn: 
    //      - 2D map: unordered_map<int, unordered_map<int, bool> >
    //      - surrounding look-up: dx, dy and their condition
    //      - clear/clean mind and program flow. 
    
    unordered_map<int, unordered_map<int, bool> > vis;
    int n, m;
    vector<vector<char>> mboard;
    int dx[3] = {-1, 0, 1};
    int dy[3] = {-1, 0, 1};
    void dfs(int x, int y) {
        if(mboard[x][y] == 'M') {
            mboard[x][y] = 'X';
            return;
        }
        vis[x][y] = 1;
        int mines = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(x + dx[i] >= n || x + dx[i] < 0 || y + dy[j] >= m || y + dy[j] < 0) continue;
                if(dx[i] == 0 && dy[j] == 0) continue;
                if(mboard[x + dx[i]][y + dy[j]] == 'M') mines++;
            }
        }
        if(mines > 0) {
            mboard[x][y] = mines + '0';
            return;
        }
        mboard[x][y] = 'B';
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(x + dx[i] >= n || x + dx[i] < 0 || y + dy[j] >= m || y + dy[j] < 0) continue;
                if(dx[i] == 0 && dx[j] == 0) continue;
                if(mboard[x + dx[i]][y + dy[j]] == 'E' && !vis[x + dx[i]][y + dy[j]]){
                    dfs(x + dx[i], y + dy[j]);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        mboard = board;
        dfs(click[0], click[1]);
        return mboard;
    }
    
    
    /*
    char helper_reveal(vector<vector<char>>& board, int pos, int xlen, int ylen){
        int xpos = pos/ylen; 
        int ypos = pos%ylen; 
        
        int counter = 0; 
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // this is a BFS exploration.. 
        // use a queue and a hashtable to represent viewed position.. 
        
        if(board.size() == 0) return board; 
        if(board[0].size() == 0) return board; 
        
        // use x*ylen+y
        int ylen = board[0].size(); 
        int xlen = board.size(); 
        vector<int> bfsqueue; 
        map<int, int> checked; 
        
        if(board[click[0]][click[1]] == )
        
        
        return board; 
    }
    
    
    */
};
