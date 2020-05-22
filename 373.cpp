class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // if use a normal pq, just nums1 and nums2 k for each is enough.. 
        // if having a queue with size k, it will be better.. 
        
        auto compare = [&](pair<int, int> a, pair<int, int> b){ return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
	    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> que(compare);
        
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        if (!n or !m) return res;
        
        for (int i = 0; i < n; ++i) {
            que.push(make_pair(i, 0));
        }
        
        while (k-- and !que.empty()) {
            pair<int, int> cur = que.top(); que.pop();
            // loop over k minimum possible pairs using minheap
            // 0,0 -> 0,1?1,0 -> 0,2?1,0 etc.. 
            // thus fixed size!! 
            res.emplace_back(vector<int>({nums1[cur.first], nums2[cur.second]}));
            if (cur.second + 1 < m) {
                que.push(make_pair(cur.first, cur.second + 1));
            }
        }
        return res;
        
    }
};
