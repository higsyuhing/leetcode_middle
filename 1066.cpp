class Solution {
public:
    int minManHaDis(vector<vector<int>> &ws, vector<vector<int>> &bs) {
        int m = ws.size(), n = bs.size();//m <= n based on the question;
        vector<vector<int>> memo(1<<m, vector<int>(1<<n, -1));
        int state1 = 0, state2 = 0;
        int res = dfs(0, ws, state1, bs, state2, memo);
        //cout<<res<<endl;
        return res;
    }
 
private:
    int dfs(int i, vector<vector<int>> &ws, int st1, vector<vector<int>> &bs, int st2, vector<vector<int>> &memo) {
        if(i==ws.size()) return 0;//all the workers are assigned;
        if(memo[st1][st2] != -1) return memo[st1][st2];//calculated;
        int min_dis = INT_MAX;
        for(int j = 0; j < bs.size(); ++j) {//try all the bikes;
            if((st2>>j) & 1) continue;//if the bike is used;
            int one_dis = abs(ws[i][0] - bs[j][0]) + abs(ws[i][1] - bs[j][1]);
            one_dis += dfs(i+1, ws, st1 | (1<<i), bs, st2 | (1<<j), memo);//total dis in this case;
            min_dis = min(min_dis, one_dis);//min distance;
        }
        return memo[st1][st2] = min_dis;//memorize min distance;
    }
};

/*
1. this question is solved by: 
    1. bit representation for compress storage, 2. DP for avoiding similar sub-scenarios
2. this code is from: https://algorithm-notes-allinone.blogspot.com/2019/09/leetcode-1066-campus-bikes-ii.html
3. code style discussion on: https://codereview.stackexchange.com/questions/226874/leetcode-1066-campus-bikes-ii

*/



