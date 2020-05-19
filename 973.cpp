class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // a simple hashmap + priority queue?? 
        // reference: min heap in: 
        //      https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/
        typedef pair<int, int> pqnode; // the index in points
        priority_queue<pqnode, vector<pqnode>, greater<pqnode> > pri_queue; 
        
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0]; 
            int y = points[i][1]; 
            pri_queue.push(make_pair(x*x+y*y, i)); 
        }
        
        vector<vector<int>> res; 
        for(int i = 0; i < K; i++){
            pqnode temp = pri_queue.top(); 
            res.push_back(points[temp.second]); 
            pri_queue.pop(); 
        }
        
        return res; 
    }
};

/*
// using comparison is faster?? 

class Solution {
    static int distance(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int begin = 0;
        int end = points.size() - 1;
        --K;
        
        while (begin <= end) {
            int pivot_idx = begin;
            int pivot = distance(points[end]);
            
            for (int i = pivot_idx; i < end; ++i) {
                if (distance(points[i]) > pivot) {
                    continue;
                } else {
                    swap(points[i], points[pivot_idx]);
                    ++pivot_idx;
                }
            }
            swap(points[pivot_idx], points[end]);
            
            if (pivot_idx == K) break;
            if (K < pivot_idx) end = pivot_idx - 1;
            else begin = pivot_idx + 1;
        }
        
        vector<vector<int>> ans(points.begin(), points.begin() + K + 1);
        return ans;
    }
};

*/
