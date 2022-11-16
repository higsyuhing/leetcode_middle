class SnapshotArray {
public:
    int versionid; 
    vector<vector<pair<int, int>>> storage; // version id, value

    SnapshotArray(int length) {
        storage.reserve(length); 
        versionid = 0; 
        for (int i = 0; i < length; i++){
            vector<pair<int, int>> tmp; 
            tmp.push_back(make_pair(0, 0)); 
            storage.push_back(tmp); 
        }
    }
    
    void set(int index, int val) {
        // if current version > last version, create new version for that
        // else update the current version
        vector<pair<int, int>>& local = storage[index]; 
        pair<int, int>& last = local[local.size()-1]; 
        if (versionid > last.first){
            local.push_back(make_pair(versionid, val)); 
        }
        else{
            last.second = val; 
        }
    }
    
    int snap() {
        versionid++; 
        return versionid - 1; 
    }
    
    int get(int index, int snap_id) {
        // binary search.. 
        // e.g. version ids: 0, 3, 8, .. 
        // thus version 0-2 will use version 0's value; 
        // 3-7 will use version 3's value (no update/'set' between version 4-7)
        vector<pair<int, int>>& local = storage[index]; 
        int l, r; 
        l = 0; r = local.size(); // [l, r)
        while (l < (r-1)){
            int m = (l+r) / 2; 
            int vid = local[m].first; 
            if (vid <= snap_id) l = m; 
            else r = m; 
        }
        return local[l].second; 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
