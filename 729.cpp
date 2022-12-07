class MyCalendar {
public:
    vector<pair<int, int>> records; 
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (records.size() == 0){
            records.push_back(make_pair(start, end)); 
            return true; 
        }
        // if (records.size() == 1){
        //     auto &record = records[0]; 
        //     if (start >= record.second){
        //         records.push_back(make_pair(start, end)); 
        //         return true; 
        //     }
        //     if (end <= record.first){
        //         auto np = make_pair(start, end); 
        //         records.insert(records.begin(), np); 
        //         return true; 
        //     }
        //     return false; 
        // }

        // binary search.. using start.. 
        int l = 0; 
        int r = records.size(); 
        while (l < r){
            int m = (l+r)/2; 
            auto &record = records[m]; 
            if (start < record.first)
                r = m; 
            else
                l = m + 1; 
        }
        // fill on the left side of 'l'

        if (l == 0){
            if (end <= records[0].first){
                auto np = make_pair(start, end); 
                records.insert(records.begin(), np); 
                return true; 
            }
            return false; 
        }
        if (l == records.size()){
            if (start >= records[records.size()-1].second){
                records.push_back(make_pair(start, end)); 
                return true; 
            }
            return false; 
        }
        if (start >= records[l-1].second && end <= records[l].first){
            auto np = make_pair(start, end); 
            records.insert(records.begin()+l, np); 
            return true; 
        }
        return false; 
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 /*
 use map: lower_bound...
 */
