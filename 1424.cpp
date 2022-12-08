class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> diagvec; 
        int totalsize = 0; 
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums[i].size(); j++){
                int tar = i+j; // always from small to large
                if (tar == diagvec.size()){
                    vector<int> tmp; 
                    tmp.push_back(nums[i][j]); 
                    diagvec.push_back(tmp); 
                }
                else{
                    diagvec[tar].push_back(nums[i][j]); 
                }
            }
            totalsize += nums[i].size(); 
        }

        vector<int> ret(totalsize, 0); 
        int curr = 0; 
        for (int i = 0; i < diagvec.size(); i++){
            for (int j = 0; j < diagvec[i].size(); j++){
                int index = diagvec[i].size() - 1 - j; 
                ret[curr] = (diagvec[i][index]); 
                curr++; 
            }
        }
        return ret; 
    }
};
