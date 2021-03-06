class Solution {
public:
    const vector<pair<int,int>> d_directions = {
        {0, -1}, {1, 0}, {0, 1}, {-1, 0}
    };

    void bfs(
        queue<pair<int,int>>& q
      , vector<vector<bool>>& ocean
      , const vector<vector<int>>& matrix
      , int r
      , int c
    ) {
        while (! q.empty())
        {
            auto& cur = q.front();
            int i = cur.first;
            int j = cur.second;
            q.pop();
            
            for (const pair<int, int>& p : d_directions)
            {
                int x = i + p.first;
                int y = j + p.second;
                
                if (x < 0 || x >= r || y < 0 || y >= c)
                    continue;
                
                if (ocean[x][y] == false && matrix[x][y] >= matrix[i][j])
                {
                    ocean[x][y] = true;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(const vector<vector<int>>& matrix) {
        
        // this is really boring.......
        
        if (matrix.empty())
            return {};

        int r = matrix.size();
        int c = matrix[0].size();
        queue<pair<int,int>> q;

        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        for (int i = 0; i < c; i ++)
        {
            pacific[0][i] = true;
            q.push(make_pair(0, i));   
        }
        for (int i = 1; i < r; i ++)
        {
            pacific[i][0] = true;
            q.push(make_pair(i, 0));   
        }
        bfs(q, pacific, matrix, r, c);
        
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));
        for (int i = 0; i < c; i ++)
        {
            atlantic[r - 1][i] = true;
            q.push(make_pair(r - 1, i));   
        }
        for (int i = 0; i < r - 1; i ++)
        {
            atlantic[i][c - 1] = true;
            q.push(make_pair(i, c - 1));   
        }
        bfs(q, atlantic, matrix, r, c);

        vector<vector<int>> res;
        for (int i = 0; i < r; ++ i)
            for (int j = 0; j < c; ++ j)
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back(vector<int>{i, j});
        
        return res;
    }
};
