class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // search for all sub-arr, note that all numbers are positive
        // sliding window
        queue<pair<int, int>> overlapq; // [start, end)
        int lastminlen = -1; 
        int ret = -1; 
        int l, r; 
        int sum = 0; 
        for (l = 0, r = 0; r <= arr.size(); ){ // sub array [l, r)
            if (sum == target){
                ////// Jamie's algorithm
                // 1. compare with current in queue, if not overlap, pop
                //      check a smaller lastminlen
                // 2. check if curr.len + lastminlen < ret, update ret
                // 3. push curr into queue
                auto p = make_pair(l, r); 
                while (!overlapq.empty()){
                    auto &comp = overlapq.front(); 
                    if (comp.second <= l){ // no overlap
                        int complen = comp.second - comp.first; 
                        lastminlen = (lastminlen == -1) ? complen : lastminlen; 
                        lastminlen = (lastminlen > complen) ? complen : lastminlen; 
                        overlapq.pop(); 
                    }
                    else{
                        break; 
                    }
                }
                if (lastminlen != -1){
                    int tmplen = (r-l+lastminlen); 
                    ret = (ret == -1) ? tmplen : ret; 
                    ret = (ret > tmplen) ? tmplen : ret; 
                }
                overlapq.push(p); 

                if (r == arr.size())
                    break; 
                sum += arr[r]; 
                r++; 
            }
            else if (sum < target){
                if (r == arr.size())
                    break; 
                sum += arr[r]; 
                r++; 
            }
            else{
                sum -= arr[l]; 
                l++; 
            }
        }
        return ret; 


    }
};

/*
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // // find all sub array attributes in arr
        // vector<int> prefix(arr.size()+1, 0); 
        // int sum = 0; 
        // for (int i = 0; i < arr.size(); i++){
        //     sum += arr[i]; 
        //     prefix[i+1] = sum; 
        // }

        // search for all sub-arr, note that all numbers are positive
        // sliding window
        vector<pair<int, int>> subarr; // length, start, we use [start, end)
        int l, r; 
        int sum = 0; 
        for (l = 0, r = 0; r <= arr.size(); ){ // sub array [l, r)
            if (sum == target){
                subarr.push_back(make_pair(r-l, l)); 
                if (r == arr.size())
                    break; 
                sum += arr[r]; 
                r++; 
            }
            else if (sum < target){
                if (r == arr.size())
                    break; 
                sum += arr[r]; 
                r++; 
            }
            else{
                sum -= arr[l]; 
                l++; 
            }
        }
        if (subarr.size() <= 1){
            return -1; 
        }

        // for (auto& p : subarr){
        //     cout << p.first << ", " << p.second << ", " << (p.first + p.second) << endl; 
        // }

        sort(subarr.begin(), subarr.end()); 
        int curr, next; 
        curr = 0; 
        next = INT_MAX; // smallest the other pair
        sum = INT_MAX; 
        while (1){
            if (curr >= next || curr == subarr.size()){
                break; 
            }
            int start = subarr[curr].second; 
            int end = subarr[curr].first + subarr[curr].second; 
            for (int i = curr+1; i < subarr.size(); i++){
                // check overlap between curr and i
                int tmps = subarr[i].second; 
                int tmpe = subarr[i].first + subarr[i].second; 
                if ((end <= tmps) || (start >= tmpe)){
                    // find the smallest pair
                    int tmpsum = subarr[curr].first + subarr[i].first; 
                    sum = (sum > tmpsum) ? tmpsum : sum; 
                    next = (next > i) ? i : next; 
                    break; 
                }
            }
            curr++; 
        }

        sum = (sum == INT_MAX) ? -1 : sum; 
        return sum; 
    }
};

*/
