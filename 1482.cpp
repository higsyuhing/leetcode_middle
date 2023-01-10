class Solution {
public:

    bool check(vector<int>& bloomDay, int mid, int m, int k){
        int curr = 0; 
        for (int bloom : bloomDay){
            if (bloom <= mid){
                curr++; 
                if (curr == k){
                    m--; 
                    if (m == 0)
                        break; 
                    curr = 0; 
                }
            }
            else{
                curr = 0; 
            }
        }

        return (m == 0); 
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // binary search for the date, and check each of them. 
        uint64_t len = bloomDay.size(); 
        if (len < (((uint64_t)m)*k)) // need more flowers
            return -1; 

        int maxdate = 0; 
        for (int day : bloomDay){
            maxdate = (maxdate < day) ? day : maxdate; 
        }

        int l = 0; 
        int r = maxdate; 
        // l: not OK, r: OK
        while (l < (r-1)){
            int mid = (l+r) / 2; 
            if (check(bloomDay, mid, m, k) == true){
                // we can collect with mid date, then we can move earlier
                r = mid; 
            }
            else{
                l = mid; 
            }
        }

        return r; 
    }
};
