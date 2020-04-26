class Solution {
public:
    bool inrange(int i,int n,bool*visited)
    {
        return (i<=n && !visited[i]);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        // this is so boring.. 
        
        // i am currently as position 1
        int n = board.size()*board.size();
        int * ladderboard = new int[n+1];
        
        //copying the board entries into a linear array
        bool oddcol = true;
        int index = 1;
        for(int i=board.size()-1;i>=0;i--)
        {
            if(oddcol)
            {
                for(int j=0;j<board.size();j++)
                {
                    ladderboard[index++] = board[i][j];
                }
            }
            else
            {
                for(int j=board.size()-1;j>=0;j--)
                {
                    ladderboard[index++] = board[i][j];
                }
            }
            if(oddcol) oddcol = false;
            else oddcol = true;
        }
        index = index-1;
        
        // linear ladderboard is ready
        // make a visited array 
        bool * visited = new bool[n+1];
        for(int i=1;i<=n;i++) visited[i] = false;
        
        // now we will take a queue and we will store the value
        //(where we go) and the moves to reach that node
        queue<pair<int,int>> q;
        q.push({1,0}); // means we are at position 1
                       // we have taken 0 steps till now
        // we are required to reach at position 36
        visited[1] = true;
        int ans = -1;
        bool found = false;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front.first==n)
            {
                ans = front.second;
                found = true;
                break;
            }
            for(int j=front.first+1;j<=front.first+6;j++)
            {
                if(inrange(j,n,visited))
                {
                    if(ladderboard[j]==-1)
                    {
                        q.push({j,front.second+1});
                        visited[j] = true;
                    }
                    else
                    {
                        q.push({ladderboard[j],front.second+1});
                        visited[j]= true;
                    }
                }
            }
            if(found) break;
        } 
        return ans;
    }
};
