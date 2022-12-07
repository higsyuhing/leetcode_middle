
    // Compares two intervals according to starting times.
    bool compareInterval(vector<int>& i1, vector<int>& i2)
    {
        return (i1[1] < i2[1]);
    }

class Solution {
public:

    int videoStitching(vector<vector<int>>& clips, int time) {
        // greedy
        sort(clips.begin(), clips.end(), compareInterval); // sort by end time

        int ret = 1; // currently we have 1
        int currpos = 0; 
        for (int i = 0; i < clips.size(); i++){
            if (clips[i][0] == 0){
                currpos = (clips[i][1] > currpos) ? clips[i][1] : currpos; 
            }
        }
        if (currpos == 0)
            return -1; // no one has start=0

        while (currpos < time){
            // binary search to find the boundary end: 
            int l = 0; 
            int r = clips.size(); 
            while (l < r){
                int m = (l+r)/2; 
                auto &clip = clips[m]; 
                if (currpos < clip[1])
                    r = m; 
                else
                    l = m+1; 
            }
            // boundary is on the left side of l
            // currpos >= clip[l-1].second, currpos < clip[l].second
            int nextpos = currpos; 
            for (int i = l; i < clips.size(); i++){
                if (clips[i][0] <= currpos){
                    nextpos = (clips[i][1] > nextpos) ? clips[i][1] : nextpos; 
                }
            }
            if (nextpos == currpos)
                return -1; 

            ret++; 
            currpos = nextpos; 
        }

        return ret; 
    }
};
