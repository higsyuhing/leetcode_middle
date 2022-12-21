class Solution {
public:

    // return the time to collect this sub-tree
    int rearrange(vector<vector<int>>& hash, vector<bool>& hasApple, int id, int par){
        vector<int>& curr = hash[id]; 
        int applec = 0; 
        for (int i = 0; i < curr.size(); i++){
            int child = curr[i]; 
            if (child == par)
                continue; 
            // child
            applec += rearrange(hash, hasApple, child, id); 
        }

        if (applec > 0){
            return (applec + 2); 
        }
        if (hasApple[id] == true)
            return 2; 
        else
            return 0; 
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // tree structure: array of int[3]+bool[1], parent, left, right, child has apple? 
        // or DFS the tree structure.. 

        vector<int> tmp; 
        vector<vector<int>> hash(n, tmp); 
        for (vector<int>& p : edges){
            int s = p[0]; 
            int e = p[1]; 
            hash[s].push_back(e); 
            hash[e].push_back(s); 
        }

        // re-arrange
        int ret = rearrange(hash, hasApple, 0, -1); 
        ret = (ret > 0) ? (ret-2) : ret; 
        return ret; 
    }
};
