class Solution {
public:
    
    bool inner_searchM(vector<vector<int>>& matrix, int target, 
                      int lr, int lc, int rr, int rc){
        if(lr == rr) return false; 
        if(lc == rc) return false; 
        
        int midr = (lr+rr)/2; 
        int midc = (lc+rc)/2; 
        int temp = matrix[midr][midc]; 
        
        if(temp == target) return true; 
        
        bool res, res1, res2; 
        if(temp > target){
            res = inner_searchM(matrix, target, lr, lc, midr, midc); 
            res1 = inner_searchM(matrix, target, midr, lc, rr, midc); 
            res2 = inner_searchM(matrix, target, lr, midc, midr, rc); 
        }
        else{
            res = inner_searchM(matrix, target, midr+1, midc+1, rr, rc); 
            res1 = inner_searchM(matrix, target, lr, midc+1, midr+1, rc); 
            res2 = inner_searchM(matrix, target, midr+1, lc, rr, midc+1); 
        }
        return res || res1 || res2; 
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // use inner function(matrix, target, lr, lc, rr, rc)
        // row and col is [0, n)
        
        if(matrix.size() == 0) return false; 
        
        return inner_searchM(matrix, target, 
                             0, 0, matrix.size(), matrix[0].size()); 
        
    }
};

/*
// hmmmm, smart. 
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int n = mat.size();
        if (n == 0) {
            return false;
        }
        int m = mat[0].size();
        if (m == 0) {
            return false;
        }

        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int v = mat[i][j];
            if (v == target) {
                return true;
            } else if (v < target) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
};

*/
