class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        int n = A.size();
        long sum_t = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum_t += i*A[i];
            sum += A[i];
        }
    
        long res = sum_t;
        for (int i = 1; i < n; i++) {
            long p = (long)n*A[n-i];
            sum_t = sum_t + sum - p;
            res = max(res, sum_t);
        }
        
        return res;
    }
};
