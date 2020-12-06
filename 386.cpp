class Solution {
public:
    void recursive(vector<int>& res, int i, int n){
        if(i <= n){
            res.push_back(i); 
            for(int j = 0; j < 10; j++){
                recursive(res, 10*i+j, n); 
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> res; 
        if(n == 0) return res; 
        for(int i = 1; i < 10; i++){
            recursive(res, i, n); 
        }
        return res; 
    }
    /*
    // iterative structure.. much slower.. 
    vector<int> lexicalOrder(int n) {
        vector<int> res; 
        if(n == 0) return res; 
        stack<int> mystack; 
        for(int i = 1; i < 10; i++){
            mystack.push(i); 
            while(!mystack.empty()){
                int curr = mystack.top(); 
                mystack.pop(); 
                
                if(curr <= n){
                    res.push_back(curr); 
                    for(int j = 9; j >= 0; j--) mystack.push(curr*10+j); 
                }
            }
        }
        return res; 
    }
    */
};

/*
// solution is better! 
    vector<int> lexicalOrder(int n) {
        vector<int> vec(n);
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            vec[i] = curr;
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                if (curr >= n) {
                    curr /= 10;
                }
                ++curr;
                while (curr % 10 == 0) {
                    curr /= 10;
                }
            }
        }
        return vec;
    }

*/
