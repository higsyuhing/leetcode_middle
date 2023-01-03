class Solution {
public:
    // binary search for intervals with op=0or1 for start/end
    // provide a pos, return the index in intervals that: 
    //  intervals[index-1][op] <= pos < intervals[index][op]
    // index can be 0 for leftmost and intervals.size() for rightmost
    int binsearch(vector<vector<int>>& intervals, int op, int pos){
        int l, r; 
        l = 0; r = intervals.size(); 
        while (l < r){
            int m = (l+r)/2; 
            int val = intervals[m][op]; 
            if (pos < val){
                r = m; 
            }
            else{
                l = m+1; 
            }
        }
        return l; 
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size(); 
        int left = binsearch(intervals, 1, newInterval[0]); 
        int right = binsearch(intervals, 0, newInterval[1]); 

        if (right == 0){ // insert on the left most, no overlap
            auto it = intervals.begin(); 
            intervals.insert(it, newInterval); 
            return intervals; 
        }
        if (left == len){ // on the rightmost, but may overlap
            if (intervals[len-1][1] == newInterval[0]){
                intervals[len-1][1] = newInterval[1]; 
                return intervals; 
            }
            else{
                intervals.push_back(newInterval); 
                return intervals; 
            }
        }

        // we need to update left, right as a index range [left, right], 
        // that all intervals in between should be erased. 
        // and we will generate a new newInterval
        if (left == 0){
            newInterval[0] = (intervals[0][0] < newInterval[0]) ? intervals[0][0] : newInterval[0]; 
        }
        else{
            if (newInterval[0] == intervals[left-1][1]){
                newInterval[0] = intervals[left-1][0]; 
                left = left-1; 
            }
            else{
                newInterval[0] = (intervals[left][0] < newInterval[0]) ? intervals[left][0] : newInterval[0]; 
            }
        }

        newInterval[1] = (intervals[right-1][1] > newInterval[1]) ? intervals[right-1][1] : newInterval[1]; 

        auto it = intervals.begin(); 
        auto itleft = it + left; 
        auto itright = it + right; 
        auto itnext = intervals.erase(itleft, itright); 
        intervals.insert(itnext, newInterval); 

        return intervals; 
    }
};



