struct less_than_key
{
    inline bool operator() (const vector<int>& intv1, const vector<int>& intv2)
    {
        if (intv1[1] != intv2[1])
            return (intv1[1] < intv2[1]); // ending first sort
        else
            return (intv1[0] < intv2[0]); // if same ending, start first sort
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less_than_key()); 
        // for (auto& intv : intervals){
        //     cout << intv[0] << ", " << intv[1] << endl; 
        // }

        int ret = 0; 
        int last = intervals[0][1]; // first end
        for (int i = 1; i < intervals.size(); i++){
            auto& intv = intervals[i]; 
            if (last <= intv[0]){
                last = intv[1]; 
            }
            else{
                ret++; 
            }
        }

        return ret; 
    }
};



