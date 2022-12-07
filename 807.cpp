class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // max for each row and col, maxr[n], maxc[n]
        // for each grid[r][c], we can reach min(maxr[r], maxc[c])

        vector<int> maxr(grid.size(), 0); 
        vector<int> maxc(grid[0].size(), 0); 
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                int curr = grid[i][j]; 
                maxr[i] = (curr > maxr[i]) ? curr : maxr[i]; 
                maxc[j] = (curr > maxc[j]) ? curr : maxc[j]; 
            }
        }

        int res = 0; 
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                int curr = grid[i][j]; 
                int top = (maxr[i] > maxc[j]) ? maxc[j] : maxr[i]; 
                res += (top - curr); 
            }
        }

        return res; 
    }
};


