class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort, and looking back to front
        // maintaining the last arrow, greedy
        sort(points.begin(), points.end()); 
        int64_t last = 1LL << 32; 
        int ret = 0; 
        for (int i = points.size()-1; i >= 0; i--){
            int s = points[i][0]; 
            int e = points[i][1]; 
            if (e >= last)
                continue; 
            ret++; // arrow at 's'
            last = s; 
        }

        return ret; 
    }
};
