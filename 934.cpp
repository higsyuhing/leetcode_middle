class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    void dfs(vector<vector<int>>& A,queue<pair<int,int>>& q,int u,int v){
        //, set<pair<int, int>>& checkedset
        int m=A.size();
        int n=A[0].size();
        A[u][v]=-1;
        //checkedset.insert({u, v});
        q.push({u,v});
        for(int i=0;i<4;i++){
            int x=u+dx[i];
            int y=v+dy[i];
            if(x>=0 && x<m && y>=0 && y<n && A[x][y]==1){
                // && (checkedset.find({x,y}) == checkedset.end())
                dfs(A,q,x,y);//,checkedset
            }
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& A) {
        
        // modify other answer.. 
        
        // core point: identify boundary, island set. 
        // BFS for shorest path? 
        // label number for: 1 step point, 2 step point.. K step point reaches
        
        // find all connected node to a queue, and a checked set
        // then bfs on these nodes, check surroundings
        //      if 1: check if in set, if not, return length
        //      else (0): if not in set, label checked, put in queue
        //   length++
        
        // fxxk.. using set is too costly.. instead of directly label them in A..
        
        int m=A.size();
        int n=A[0].size();
        int temp=0;
        queue<pair<int,int>> q;
        //set<pair<int, int>> checkedset; 
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]==1){
                    temp=1;
                    dfs(A,q,i,j);//, checkedset
                    break;
                }
            }
            if(temp==1){
                break;
            }
        }
        
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto& it=q.front();
                int a=it.first;
                int b=it.second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x=a+dx[i];
                    int y=b+dy[i];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(A[x][y]==1){
                            // && (checkedset.find({x,y}) == checkedset.end())
                            return ans;
                        }
                        if(A[x][y]==0){
                            q.push({x,y});
                            A[x][y]=-1;
                            //checkedset.insert({x, y});
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
