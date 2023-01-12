
class CompareMax
{
public:
    bool operator() (pair<int, int>& a, pair<int, int>& b)
    {
        return a.first < b.first;
    }
};

class CompareMin
{
public:
    bool operator() (pair<int, int>& a, pair<int, int>& b)
    {
        return a.first >= b.first;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // use sliding window, keep minval, maxval and corresponding index
        // if new one: 
        //      is new min: compare with the max, if range > limit: 
        //          shrink until maxindex+1, re-try new max, until match
        //          get new max
        //      is new max: compare with the min, if range > limit: 
        //          shrink until minindex+1, re-try new min, until match
        //          get new min
        //      in between: 
        //          do nothing.. update result? 
        // 
        // sliding window requirement: 
        //      fast in-order insert, delete -> array/queue
        //      fast get max/min
        // use 2 heap: max, min, keep the index also
        // when compute new max/min, check index first, if < current start, pop. 
        
        // but 2 heap is OK, and each new value should be added into the heap. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMax> maxq; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMin> minq; 
        
        // for (int i = 0; i < nums.size(); ++i){
        //     maxq.push(make_pair(nums[i], i)); 
        //     minq.push(make_pair(nums[i], i)); 
        // }

        // while (!maxq.empty()){
        //     cout << maxq.top().first << ", " << maxq.top().second << endl; 
        //     maxq.pop(); 
        // }
        // cout << endl; 
        // while (!minq.empty()){
        //     cout << minq.top().first << ", " << minq.top().second << endl; 
        //     minq.pop(); 
        // }
        // cout << endl; 

        int start = 0; // [start, i]
        int ret = 0; 
        for (int i = 0; i < nums.size(); ++i){
            int curr = nums[i]; 
            maxq.push(make_pair(curr, i)); 
            minq.push(make_pair(curr, i)); 

            while (maxq.top().second < start){
                maxq.pop(); 
            }
            while (minq.top().second < start){
                minq.pop(); 
            }

            // compare
            int currmax = maxq.top().first; 
            int currmin = minq.top().first; 
            if ((currmax - currmin) > limit){
                if (curr == currmin){
                    // go over max.. 
                    while ((maxq.top().first - currmin) > limit){
                        start = maxq.top().second + 1; 
                        while (maxq.top().second < start){
                            maxq.pop(); 
                        }
                    }
                }
                else if (curr == currmax){
                    // go over min.. 
                    while ((currmax - minq.top().first) > limit){
                        start = minq.top().second + 1; 
                        while (minq.top().second < start){
                            minq.pop(); 
                        }
                    }
                }
            }
            // else do nothing. 

            // update result
            ret = ((i - start + 1) > ret) ? (i - start + 1) : ret; 
        }

        
        return ret; 
    }
};






