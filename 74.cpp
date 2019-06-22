class Solution {
public:
    bool helpfunc_binarysearch(vector<int>& row, int lenj, int target){
        // several early lines has this case
        if(target > row[lenj-1]) return false; 
        
        // standard binary search
        int l = 0; 
        int r = lenj-1; 
        while (l <= r){ 
            int m = l + (r - l) / 2; 
            
            // Check if x is present at mid 
            if (row[m] == target) 
                return true; 
            
            // If x greater, ignore left half 
            if (row[m] < target) 
                l = m + 1; 
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
        
        return false; 
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // since after the first element, the order is not decided.. 
        // 1. find how many lines has this potential possibility
        // 2. binary search for each line
        
        int i, j, leni, lenj, temp1, temp2; 
        leni = matrix.size(); 
        if(leni == 0) return false; 
        lenj = matrix[0].size(); 
        if(lenj == 0) return false; 
        
        int posrow = 0; 
        while(matrix[posrow][0] <= target){
            posrow++; 
            if(posrow == leni) break; 
        }
        
        for(i = 0; i < posrow; i++){
            if(helpfunc_binarysearch(matrix[i], lenj, target)) return true; 
        }
        
        return false; 
    }
};
