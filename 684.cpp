class Solution {
public:
    int dfs(map<int, vector<pair<int, int> > >& hash, vector<bool>& visited, 
            stack<int>& dfsstack, int curr){
        
        if (visited[curr-1] == true){
            return curr; // merge point
        }

        visited[curr-1] = true; 
        vector<pair<int, int> >& neighbors = hash[curr]; 
        for (auto& neighbor : neighbors){
            int next = neighbor.first; 
            if (!dfsstack.empty()){
                if (next == dfsstack.top())
                    continue; 
            }
            // search next. 
            dfsstack.push(curr); 
            int ret = dfs(hash, visited, dfsstack, next); 
            if (ret != -1)
                return ret; 
            dfsstack.pop(); 
        }

        // done all neighbors but not found. 
        return -1; 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // it is just a cycle find algo.. 
        // same as 685, use a hashmap with child->edges-index
        // exactly 3 cases as 685

        // i want to use a new way.. just store its neighbor.. 
        // node i: vector neighbors: pair(node j, edges index)
        map<int, vector<pair<int, int> > > hash; 
        int index = 0; 
        for (auto& edge : edges){
            int s = edge[0]; 
            int e = edge[1]; 
            if (hash.find(s) == hash.end()){
                vector<pair<int, int> > tmp; 
                tmp.push_back(make_pair(e, index)); 
                hash[s] = tmp; 
            }
            else{
                hash[s].push_back(make_pair(e, index)); 
            }
            if (hash.find(e) == hash.end()){
                vector<pair<int, int> > tmp; 
                tmp.push_back(make_pair(s, index)); 
                hash[e] = tmp; 
            }
            else{
                hash[e].push_back(make_pair(s, index)); 
            }
            index++; 
        }

        // loop search.. 
        vector<bool> visited(edges.size(), false); 
        stack<int> dfsstack; 
        int curr = 1; // start with node 1
        curr = dfs(hash, visited, dfsstack, curr); 
        if (curr == -1){
            cout << "Error!! " << endl; 
            vector<int> ret; 
            return ret; 
        }

        // debug
        // while (!dfsstack.empty()){
        //     cout << dfsstack.top() << endl; ; 
        //     dfsstack.pop(); 
        // }
        // cout << "curr: " << curr << endl; 
        //     vector<int> ret; 
        //     return ret; 

        // curr is in dfsstack
        int mergenode = curr; 
        int next = -1; 
        index = -1; // return index
        while (next != mergenode){
            next = dfsstack.top(); 
            dfsstack.pop(); 
            // curr->next pair. 
            vector<pair<int, int> >& neighbors = hash[curr]; 
            int candidate = -1; 
            for (auto& neighbor : neighbors){
                candidate = neighbor.first; 
                if (candidate == next){
                    index = (index < neighbor.second) ? neighbor.second : index; 
                    candidate = -2; // complete
                    break; 
                }
            }
            if (candidate != -2){
                cout << "Error 1.. " << curr << ", " << next << ", " << candidate << endl; 
                vector<int> ret; 
                return ret; 
            }

            curr = next; 
        }

        return edges[index]; 
    }
};




