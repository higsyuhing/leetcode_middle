class Solution {
public:
    /*
    
    // math number solution.. not understand... 
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
    
    // DP solution.. dp[n+1] = min for i in {dp[n+1-i^2]+1}
    int numSquares(int n) {
        static vector<int> dp{0};
        if(n<dp.size()) return dp[n];
        while(dp.size()<=n){
            int m=dp.size(),cur=INT_MAX;
            for(int i=1;i*i<=m;++i){
                cur=min(cur,dp[m-i*i]+1);
            } 
            dp.emplace_back(cur);
        }
        return dp[n];
    }
    
    */
    
    int numSquares(int n) {
        
        // create a array of square: 1,4,9,16 ..
        // then BFS: first choose 1,4,9, ..
        //          second, for each pair, choose number less than it
        //                  also less than (n-sum)
        //                  like: 1->1, 4->4/1, 9->9/4/1 ... 
        //          note: queue in pair<int, int>: current number/idx, and sum
        
        int maxi = (int)sqrt((double)n); 
        vector<int> squareset; 
        squareset.reserve(maxi); 
        for(int i = 1; i <= maxi; i++){
            squareset.push_back(i*i); 
        }
        
        int res = 1; 
        queue<pair<int, int>> bfsqueue; 
        for(int i = 0; i < maxi; i++){
            if(n == squareset[i]) return res; 
            bfsqueue.push(make_pair(i, squareset[i])); 
        }
        
        while(1){ // never jump out.. 
            res++; 
            int len = bfsqueue.size(); 
            //cout << len << endl; 
            for(int i = 0; i < len; i++){
                auto& curr = bfsqueue.front(); 
                int curridx = curr.first; 
                int currsum = curr.second; 
                bfsqueue.pop(); 
                
                for(int j = 0; j <= curridx; j++){
                    if((currsum + squareset[j]) == n) return res; 
                    bfsqueue.push(make_pair(j, currsum + squareset[j])); 
                }
            }
        }
        
        return 0; // never executes here.. always n*1 is OK
    }
};
