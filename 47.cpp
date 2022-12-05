class Solution {
public:
    
    void permute(int index,vector<int> arr,vector<vector<int>> &final){
        if(index==arr.size()){
            final.push_back(arr);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i!=index and arr[i]==arr[index])continue;
            cout << arr[i] << arr[index] << endl; 
            swap(arr[i],arr[index]);
            permute(index+1,arr,final);
            //swap(arr[i],arr[index]);
        } 
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        if(nums.size()==1)return vector<vector<int>> {{nums[0]}};
        sort(nums.begin(),nums.end());
        vector<vector<int>> final;
        permute(0,nums,final);
        return final;
    }
};
/*

class Solution {
public:

    void helper_func(vector<int>& nums, vector<vector<int>>& ret, 
        unordered_set<string>& hash, int level, vector<int>& order){
        // note that order is a copy based structure

        // check result
        if (level == 0){
            vector<int> tmp(nums.size(), 0); 
            string currhash; 
            for (int i = 0; i < order.size(); i++){
                tmp[i] = nums[order[i]]; 
                currhash += (to_string(nums[order[i]]) + ","); 
            }
            if (hash.count(currhash) == 0){
                ret.push_back(tmp); 
                hash.insert(currhash); 
            }
            return; 
        }

        for (int i = 0; i < level; i++){
            int val = order[level-1]; 
            order[level-1] = order[i]; 
            order[i] = val; 
            helper_func(nums, ret, hash, level-1, order); 
            order[i] = order[level-1]; 
            order[level-1] = val; 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret; 
        unordered_set<string> hash; 
        vector<int> order(nums.size(), 0); 
        for (int i = 0; i < nums.size(); i++){
            order[i] = i; 
        }
        helper_func(nums, ret, hash, nums.size(), order); 

        return ret; 
    }
};

*/
