class Solution {
public:
    
    void helper(vector<vector<int>>& result, vector<int>& tmp, 
               map<int, int>& histo, map<int, int>::iterator& it)
    {
        if(it == histo.end()){
            result.push_back(tmp); 
            return; 
        }
        
        int key = it->first; 
        int occur = it->second + 1; 
        
        for(int i = 0; i < occur; i++){
            it++; 
            helper(result, tmp, histo, it); 
            it--; 
            tmp.push_back(key); 
        }
        
        for(int i = 0; i < occur; i++){
            tmp.pop_back(); 
        }
        
        return; 
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        basically follow the thought: 
        [1,2,3]=>[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
        by remember the last one and then get rid of it..
        */
        
        map<int, int> histo; 
        for(int i = 0; i < nums.size(); i++){
            int tmp = nums[i]; 
            if(histo.find(tmp) == histo.end()){
                histo[tmp] = 1; 
            }
            else{
                histo[tmp]++; 
            }
        }
        
        vector<vector<int>> result; 
        vector<int> tmp; 
        auto it = histo.begin(); 
        helper(result, tmp, histo, it); 
        
        return result; 
    }
};
