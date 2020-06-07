class Solution {
public:

    void countcircle(vector<vector<int>> m,int s,vector<bool> &visit)
    {
        if( visit[s])
            return ;
        visit[s]=true;
        for(int i=0;i<m[0].size();i++)
        {
            if(m[s][i]==1&&s!=i)
            {
                countcircle(m,i,visit);
            }

        }
    }



    // union find method
    void Union(vector<int> &id,int p,int q)
    {
        int pid=id[p];
        int qid=id[q];

        for(int i=0;i<id.size();i++)
        {
            if(id[i]==pid)
                id[i]=qid;

        }
    }


    int findCircleNum(vector<vector<int>> M) 
    {
        // DFS.. 
        vector<bool> visit;
        for(int i=0;i<M.size();i++)
            visit.push_back(false);
        int count =0;
        for(int i=0;i< M.size();i++){
            if(visit[i]==false){
                count++;
                countcircle(M,i,visit);
            }
        }
        return count; 
/*
        // union-find
        vector<int> id;
        for(int i=0;i<M.size();i++)
            id.push_back(i);

        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[0].size();j++)
            {
                if(M[i][j]==1&&i!=j)
                {
                Union(id,i,j);
                }
            }
        }

      set<int> count;              // 00244
        for(int i=1;i<M.size();i++)
            count.insert(id[i]);

        return count.size();
*/
    }
};
