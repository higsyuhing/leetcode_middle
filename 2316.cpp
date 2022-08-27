class Solution {
public:
    
    int helper_uf_find(int curr, vector<int>& parent){
        if (parent[curr] != curr){
            parent[curr] = helper_uf_find(parent[curr], parent); 
        }
        return parent[curr]; 
    }
    
    void helper_uf_merge(int x, int y, vector<int>& parent, vector<int>& count){
        int rootx = helper_uf_find(x, parent); 
        int rooty = helper_uf_find(y, parent); 
        
        if (rootx != rooty){
            int rootlarge, rootsmall; 
            rootlarge = (count[rootx] > count[rooty]) ? rootx : rooty; 
            rootsmall = (count[rootx] > count[rooty]) ? rooty : rootx; 
            
            parent[rootsmall] = rootlarge; 
            count[rootlarge] += count[rootsmall]; 
        }
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        // 1. find all clusters
        // 2. get the number of each cluster: Ni
        //      ret = sum of (Ni*Nj)
        // use union-find, for clustering
        // then a hashmap to count the elements in each cluster
        
        vector<int> parent(n, 0); 
        for (int i = 0; i < n; i++) parent[i] = i; // init: each node has parent itself
        vector<int> count(n, 1); // currently only 1 element in each cluster. 
        
        for (vector<int>& edge : edges){
            int x = edge[0]; 
            int y = edge[1]; 
            helper_uf_merge(x, y, parent, count); 
        }
        
        set<int> hashcluster; 
        long long ret = 0; 
        long long sum = 0; 
        for (int i = 0; i < n; i++){
            int head = helper_uf_find(i, parent); 
            if (hashcluster.count(head) == 0){
                hashcluster.insert(head); 
                long long curr = (long long)count[head]; 
                ret += (sum*curr); 
                sum += curr; 
            }
        }
        return ret; 
        
        
        /*
        vector<int> sizecluster; 
        for (int i = 0; i < n; i++){
            int head = helper_uf_find(i, parent); 
            if (hashcluster.count(head) == 0){
                hashcluster.insert(head); 
                sizecluster.push_back(count[head]); 
            }
        }
        
        int len = sizecluster.size(); 
        if (len == 1) return 0; 
        long long ret = 0; 
        for (int i = 0; i < (len-1); i++){
            for (int j = i+1; j < len; j++){
                long long x, y; 
                x = (long long)sizecluster[i]; 
                y = (long long)sizecluster[j]; 
                ret += x*y; 
            }
        }
        return ret; 
        
        */
    }
};


/*
DFS is faster than union-find to get the number of elements in a cluster. 
anyway, a great learning for union-find. 

class Solution {
public:
    typedef long long ll;
    void dfs(int node, unordered_map<int,vector<int>>& m, ll& cnt, vector<int>& vis){
        vis[node] = 1;
        cnt++;
        for(auto& i: m[node]){
            if(vis[i]==0) dfs(i,m,cnt,vis);   
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m; // making adjacency list
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        ll ans = ((ll)n*(n-1))/2;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){ // as node is not visited, we find the no. of nodes in current component.
                ll cnt = 0;
                dfs(i,m,cnt,vis);
                ans -= (cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};

    void dfs(vector<int> adj[],int node,vector<bool> &vis,int &c)
    {
        c++;
        vis[node] = true;;
        
        for(auto anode: adj[node])
            if(!vis[anode]) dfs(adj,anode,vis,c);       
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int> adj[n];
        long long int ans=0,total=0;
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int c=0;
                dfs(adj,i,vis,c);       
                ans += total*c;           
                total+=c;
            }
        }
      
        return ans;
    }
*/


