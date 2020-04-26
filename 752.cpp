class Solution {
public:
    /*
    // use number operation to replace string operation, then increase speed! 
    
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool>v(10000,true);
        for(auto str:deadends)
        {
            v[stoi(str)]=false;
        }
        if(v[0]==false)
            return -1;
        v[0]=false;
        ans = -1;
        core(v,stoi(target),0);
        return ans;
    }
private:
    int ans;
    void core(vector<bool>&v, int target, int n)
    {
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int L= q.size();
            for(int i=0;i<L;++i)
            {
                int tmp = q.front();
                q.pop();
                if(tmp==target)
                {
                    ans=n;
                    break;
                }
                int a[4];
                a[3] = tmp%10;tmp/=10;
                a[2] = tmp%10;tmp/=10;
                a[1] = tmp%10;tmp/=10;
                a[0] = tmp%10;
                for(int j=0;j<4;++j)
                {
                    for(int add=-1;add<2;add+=2)
                    {
                        int t=a[j];
                        a[j]=(a[j]+10+add)%10;
                        int sum = 1000*a[0]+100*a[1]+10*a[2]+a[3];
                        if(v[sum])
                        {
                            v[sum]=false;
                            q.push(sum);
                        }
                        a[j]=t;
                    }
                }
            }
            n++;
            if(ans!=-1)
                break;
        }
    }
    
    */
    
    
    int openLock(vector<string>& deadends, string target) {
        // as matrix is a 2D BFS, this is a 4D BFS. 
        
        if(target.empty()) {
            return -1;
        }
        //store the deadends
        unordered_map<string, int> map;
        for(auto val : deadends) {
            map[val]++;
        }
        unordered_map<string, int> seen;
        queue<string> nodes;
        nodes.push("0000");
        nodes.push("NULL"); //to recognize the depth
        int depth = 0;
        while(nodes.size() > 1) {
            string val = nodes.front();
            nodes.pop();
            if(val == "NULL") {
                //processed all possible combinations of previous level,
                //so increment depth
                depth++;
                nodes.push("NULL");
            } else if(val == target) {
                return depth;
            } else if (!map[val] > 0) {
                //store all possible combinations of each level
                //that is not a deadend and that differs in 1 digit with a
                //difference of 1. So, values of d = {-1, 1}. i will toggle
                //each position in the string "xxxx". If we've already visited
                //the node then move on to the next;
                for(int i = 0; i < 4; ++i) {
                    for(int d = -1; d <=1; d+=2) {
                        int n = val[i] - '0';
                        n = (n + d + 10) % 10;
                        string curr = val.substr(0, i) + to_string(n) + val.substr(i+1);
                        if(seen[curr] == 0) {
                            seen[curr]++;
                            nodes.push(curr);
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};
