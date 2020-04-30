class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // check the youtube video to understand the idea
        // https://www.youtube.com/watch?v=HAaik49m0q0
        
        // interesting question.. 
        
        if(stones.size() <= 1) return 0;
        int N = stones.size();
        vector<int> p(N, -1);
        for(int i = 0; i < N; i++) p[i] = i;
        for(int i = 0; i < N; ++i) // one direction unite.
            for(int j = i + 1; j < N; ++j)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) 
                    unite(p, i, j);
        int res = 0;
        for(int i = 0; i < N; i++) if(p[i] != i) res++;
        return res;
    }
private:
    int find(vector<int> &p, int x) {
        if(p[x] == x) return x;
        return find(p, p[x]);
    }
    
    void unite(vector<int> &p, int x, int y) {
        int px = find(p, x);
        int py = find(p, y);
        if(px != py) p[px] = py;
    }
};
