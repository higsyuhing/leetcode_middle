class Solution {
public:
    bool isvalid(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0||j<0||j>=grid.size()||i>=grid.size()||grid[i][j]==1)
            return false;
        return true;
    }
    
    vector<vector<int>> direct={{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        // BFS searching the step, also same for DP. 
        
        queue<pair<int,int>> q;
        if(grid.empty())
            return 0;
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,-1));
        if(grid[0][0]==1)
            return -1;
        dis[0][0]=1;
        q.push({0,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            for(auto& dir:direct)
            {
                int i=p.first+dir[0];
                int j=p.second+dir[1];
                if(isvalid(i,j,grid)&&dis[i][j]==-1)
                   {
                       q.push({i,j});
                       dis[i][j]=dis[p.first][p.second]+1;
                    }
            }
        }
        return dis[n-1][n-1];
    }
};
