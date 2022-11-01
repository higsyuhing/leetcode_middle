class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // 1. we can just use 1 << i to represent powers array
        // 2. powers array is exactly the binary representation of n
        
        vector<int> powersindex; 
        int index = 0; 
        int tmp = n; 
        while (tmp > 0){
            if (tmp % 2 == 1){
                powersindex.push_back(index); 
            }
            tmp = tmp >> 1; 
            index++; 
        }
        
        // accumulate powersindex, for fast p[end] - p[start] query
        tmp = 0; 
        for (int i = 0; i < powersindex.size(); i++){
            //cout << powersindex[i] << " "; 
            index = powersindex[i]; 
            powersindex[i] += tmp; 
            tmp += index; 
        }
        //cout << endl; 
        // if start == 0, take p[end]
        // else p[end] - p[start-1]
        
        vector<int> result; 
        // we firstly use result to keep sum of indexes
        // then we convert it to real number
        for (auto &query : queries){
            int start = query[0]; 
            int end = query[1]; 
            
            tmp = (start == 0) ? 0 : powersindex[start-1]; 
            tmp = powersindex[end] - tmp; 
            result.push_back(tmp); 
            //cout << tmp << " "; 
        }
        //cout << endl;
        
        // convert to real number
        for (int i = 0; i < result.size(); i++){
            tmp = result[i]; 
            unsigned long long res = 1; 
            while (tmp > 32){
                res = res << 32; 
                res = res % (1000000007ULL); 
                tmp -= 32; 
            }
            res = res << tmp; 
            res = res % (1000000007ULL); 
            result[i] = res; 
        }
        
        return result; 
    }
};
