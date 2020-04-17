class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        // it should loop V times
        // each time search left and then right.. 
        // for each direction, have a curr pos and a next pos
        // if next is higher than curr, stay at curr
        // if next pos is -1 or len heights, stay at curr
        
        
        while (V--) drop(heights, K);
        return heights;    
    }
private:
    void drop(vector<int>& heights, int K) {
        int best = K;
        for (int d = -1; d <= 1; d += 2) {
            int i = K + d;
            while (i >= 0 && i < heights.size() 
                   && heights[i] <= heights[i - d]) {
                if (heights[i] < heights[best]) best = i;
                i += d;
            }
            if (best != K) break;
        }
        ++heights[best];
    }
};
