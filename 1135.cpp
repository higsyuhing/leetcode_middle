struct edge
{
    int vertex1;
    int vertex2;
    int value;
    edge(int v1, int v2, int val) :vertex1(v1), vertex2(v2), value(val) { }
    friend bool operator<(const edge& e1, const edge& e2)
    {
        return e1.value > e2.value;
    }
};

class Solution {
public:
    vector<int> nums;
    int Find(int x)
    {
        while(x != nums[x])
        {
            x = nums[x];
        }
        return x;
    }
    void Union(int x, int y)
    {
        int px = Find(x);
        int py = Find(y);
        if(px != py)
        {
            nums[px] = py;
        }
    }
    bool InSameSet(int x,int y)
    {
        int px = Find(x);
        int py = Find(y);
        return px == py;
    }
    int minimumCost(int N, vector<vector<int>>& conections) {
        
        priority_queue<edge> pq;
        
        nums.resize(N + 1);
        for(int i = 1; i <= N; i++)
        {
            nums[i] = i;
        }
     
        for(int i = 0; i < conections.size();i++)
        {
            int v1 = conections[i][0];
            int v2 = conections[i][1];
            int val = conections[i][2];

            pq.push(edge(v1, v2, val));
        }
        
        int res = 0;
        int edgeNum = 0;
        while(true)
        {
            if(pq.empty()) return -1;
            edge cur = pq.top();
            pq.pop();
            
            if(InSameSet(cur.vertex1, cur.vertex2))
            {
                continue;
            }
            res += cur.value;
            edgeNum++;
            if(edgeNum == N - 1) return res;
            Union(cur.vertex1, cur.vertex2);
        }
        return res;       
    }
};

/*
from: 
https://www.wandouip.com/t5i393436/
pretty good.. 

*/
