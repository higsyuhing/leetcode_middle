class Solution {
public:
    
    void helper(queue<string>& q, int n, int i, int j)
    {
        if (i == j)
        {
            q.push("0"); 
            q.push("1"); 
            q.push("8"); 
            return; 
        }
        
        string left, right; 
        if (i == 0)
        {
            left = "1869"; 
            right = "1896"; 
        }
        else if (i != j)
        {
            left = "01869"; 
            right = "01896"; 
        }
        
        if ((i+1) == j)
        {
            for (int k = 0; k < left.size(); k++)
            {
                string tmpleft(1, left[k]); 
                string tmpright(1, right[k]); 
                q.push(tmpleft+tmpright); 
            }
            return; 
        }
        
        // recursive call
        helper(q, n, i+1, j-1); 
        
        // add into string
        int len = q.size(); 
        for (int k = 0; k < len; k++)
        {
            string val = q.front(); 
            q.pop(); 
            
            for (int l = 0; l < left.size(); l++)
            {
                string tmpleft(1, left[l]); 
                string tmpright(1, right[l]); 
                q.push(tmpleft+val+tmpright); 
            }
        }
        
    }
    
    vector<string> findStrobogrammatic(int n) {
        
        // these number can have 3 categories: 
        // 1. self-symmetric: 1, 8
        // 2. self-symmetric and can be at the beginning: 0
        // 3. pair-symmetric: 69 / 96
        // cases: 
        // 1. n == 1, return 0, 1, 8
        // 2. n > 1: 
        //      n is odd: position 0 and n-1 must be self-symmetric or pair-symmetric
        //                position 1 to n-2 except the middle position: all 3
        //                middle position: self-symmetric, 0
        //      n is even: position 0 and n-1 must be self-symmetric or pair-symmetric
        //                position 1 to n-2: all 3
        // probably I can use a recursive function to implement.. 
        
        vector<string> ret; 
        if (n == 1)
        {
            ret.push_back("0"); 
            ret.push_back("1"); 
            ret.push_back("8"); 
            return ret; 
        }
        
        queue<string> q; 
        helper(q, n, 0, n-1); 
        
        // q to ret... 
        while (!q.empty())
        {
            ret.push_back(q.front()); 
            q.pop(); 
        }
        
        return ret; 
    }
};
