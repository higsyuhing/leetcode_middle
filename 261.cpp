class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // use a hashmap for the labeling
        // start from node 0, propagate the label/color to the next edge
        // if we reach a colored node, return false (cycle)
        // if we didn't complete the node, return false (forest)
        // else return true
        
        // we need to re-organize the edges structure. 
        // hashmap[node] = connection vector
        map<int, vector<int>> map_edges; 
        for(auto it = edges.begin(); it != edges.end(); it++){
            vector<int>& edge = *it; 
            // TODO: initialize?? 
            map_edges[edge[0]].push_back(edge[1]); 
            map_edges[edge[1]].push_back(edge[0]); 
        }
        
        map<int, bool> node_labels; 
        queue<int> queue_bfs; 
        map<int, bool> used_edges; // use target*2048+source to represent usage info
        
        node_labels[0] = true; 
        vector<int>& curr_edge = map_edges[0]; 
        for(auto it = curr_edge.begin(); it != curr_edge.end(); it++){
            int target = *it; 
            queue_bfs.push(target); 
            used_edges[target*2048 + 0] = true; 
        }
        
        while(!queue_bfs.empty()){
            int node = queue_bfs.front(); 
            queue_bfs.pop(); 
            //cout << "node: " << node << endl; 
            
            if(node_labels.find(node) != node_labels.end()) return false; 
            node_labels[node] = true; 
            
            curr_edge = map_edges[node]; 
            for(auto it = curr_edge.begin(); it != curr_edge.end(); it++){
                int target = *it; 
                //cout << "node target: " << target << endl; 
                
                if(used_edges[node*2048 + target] == true) continue; 
                
                queue_bfs.push(target); 
                used_edges[target*2048 + node] = true; 
            }
        }
        
        if(node_labels.size() != n) return false; 
        return true; 
    }
};

/*
wow.. union find... 

https://leetcode.com/problems/graph-valid-tree/discuss/69019/Simple-and-clean-c%2B%2B-solution-with-detailed-explanation.
https://leetcode.com/problems/graph-valid-tree/discuss/69020/8-10-lines-Union-Find-DFS-and-BFS

*/
