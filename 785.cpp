class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // basically it is same idea. but easier to implement. 
        // for each node (in fact, each non-connected subgraph)
        //      put the "tempa" node into queue
        //      then before q.size (k), test all tempa node with same color
        //      then insert tempb nodes.. 
        
        // performance result shows that DFS is much better than BFS hahaha
        
        int n=graph.size();
        if(n==0) return true;
        
        vector<int> visited(n, -1);
        queue<pair<int, int>> q;
        
        
        for(int node=0; node<n; node++){
            if(visited[node]!=-1) continue;
            int color=0;
            q.push({node, color});
            while(!q.empty()){
                int k=q.size();
                color=(color+1)%2;
                for(int i=0; i<k; i++){
                    pair<int, int> pairs=q.front();
                    q.pop();

                    visited[pairs.first]=pairs.second;
                    for(int elem : graph[pairs.first]){
                        if(visited[elem]==-1){
                            q.push({elem, color});
                        }
                        else if(visited[elem]==pairs.second)
                            return false;
                    }
                }
            }
        }
        return true;
        
        
        /*
        // bi-partitie => any assignment is fine.. 
        set<int> seta, setb; // final set
        queue<int> tempa, tempb; // temp set
        
        if(graph.size() == 0) return true; 
        
        tempa.push(0); 
        while((seta.size() + setb.size()) < graph.size()){
            
            
            
            
        }
        
        return false; 
        */
    }
};
