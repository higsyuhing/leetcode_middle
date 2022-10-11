class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // same for sub-sum.. 
        
        vector<int> prefixxor(arr.size()+1); 
        prefixxor[0] = 0; 
        int prefix = 0; 
        int index = 1; 
        for (auto ele : arr){
            prefix = prefix ^ ele; 
            prefixxor[index] = prefix; 
            index++; 
        }
        
        vector<int> ret(queries.size()); 
        
        index = 0; 
        for (auto &ele : queries){
            int left = ele[0]; 
            int right = ele[1]+1; 
            ret[index] = prefixxor[right] ^ prefixxor[left]; 
            index++; 
        }
        
        return ret; 
        
    }
};
