class Solution {
public:
    static bool comparefunc(vector<int>& thisI, vector<int>& nextI){
        vector<int>::iterator it, in; 
        it = thisI.begin();
        in = nextI.begin();
        return (*it) < (*in); 
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals; 
        
        // sort by the starting point
        sort(intervals.begin(), intervals.end(), comparefunc); 
        
        int index = 0; 
        while(index < (intervals.size()-1)){
            // index and index+1
            // merge if: next start <= this end
            if(intervals[index+1][0] <= intervals[index][1]){
                // new start = this start, new end = max{this, next end}
                if(intervals[index+1][1] > intervals[index][1]){
                    intervals[index][1] = intervals[index+1][1]; 
                }
                intervals.erase(intervals.begin()+index+1); 
            }
            else{
                index++; 
            }
        }
        
        return intervals; 
    }
    
    /*
    // accepted by too slow, the algorithm is fine, but coding style make it slow. 
    
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });
        vector<Interval> ret;
        ret.push_back( move(intervals[0]) );
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start > ret.back().end) {       // new
                ret.push_back( move(intervals[i]) );
            }
            else                                             // merge
                ret.back().end = max(ret.back().end, intervals[i].end);
        }
        return ret;
    }
};
    
    */
};
