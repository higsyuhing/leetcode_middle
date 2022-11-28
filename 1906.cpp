class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ret; 
        map<long long, int> hash; 
        for (auto& query : queries){
            long long left = query[0]; 
            long long right = query[1]; 
            long long id = ((left+1) << 32) + right; 
            if (hash.count(id) != 0){
                ret.push_back(hash[id]); 
                continue; 
            }

            set<int> tmpset; 
            for (int i = left; i <= right; i++){
                if (tmpset.count(nums[i]) == 0){
                    tmpset.insert(nums[i]); // sorted! 
                }
            }
            vector<int> tmp; 
            for (auto it = tmpset.begin(); it != tmpset.end(); it++){
                tmp.push_back(*it); 
            }

            int res = 0; 
            if (tmp.size() == 1){
                res = -1; 
            }
            else{
                res = (tmp[0] > tmp[1]) ? (tmp[0]-tmp[1]) : (tmp[1]-tmp[0]); 
                for (int i = 1; i < (tmp.size()-1); i++){
                    int a = tmp[i]; 
                    int b = tmp[i+1]; 
                    int val = (a > b) ? (a-b) : (b-a); 
                    res = (val < res) ? val : res; 
                }
            }
            ret.push_back(res); 
            hash[id] = res; 
        }
        return ret; 
    }
};

        // use segment tree
        // for every query: 
        //      if in 1 sub tree: direct return
        //      if in 2 sub trees: output from: left / right / (left-max, right-min)
        // segment tree maintains: 
        //      result, min id, max id
        // when tree merge: 
        //      use 2 results and (left-right, right-left)


/*

https://leetcode.com/problems/minimum-absolute-difference-queries/solutions/1284229/c-prefix-sum/

this question is quote tricky.. interesting. 

*/
