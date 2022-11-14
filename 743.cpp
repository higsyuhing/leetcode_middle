class Solution {
public:


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // BFS to propagate. data structure: 
        // a hash map: u -> vector of {(v, w) .. }
        // queue with pair<n, ts> // node, timestamp arrived
        // vector of shortest time init with -1
        // keep propagate if: 
        //  curr node is not labeled in timesheet, or
        //  labeled but ts is larger than the current one. 

        map<int, vector<pair<int, int>>> checkmap; 
        for (auto &time : times){
            if (checkmap.count(time[0]) == 0){
                vector<pair<int, int>> tmp; 
                tmp.push_back(make_pair(time[1], time[2])); 
                checkmap[time[0]] = tmp; 
            }
            else{
                checkmap[time[0]].push_back(make_pair(time[1], time[2])); 
            }
        }

        queue<pair<int, int>> bfsqueue; // curr node, timestamp
        vector<int> vecTime(n+1, -1); // arrive time for each node, 1-indexed

        bfsqueue.push(make_pair(k, 0)); 
        // bfsqueue.push(make_pair(-1, 0)); // ending label

        // cout << "done1" << endl; 

        while (!bfsqueue.empty()){
            auto &qele = bfsqueue.front(); 
            int node = qele.first; 
            int ts = qele.second; 
            bfsqueue.pop(); 

            // cout << node << ", " << ts << ", " << vecTime[node] << ", " << bfsqueue.size() << endl; 

            // if not labeled, or curr ts is smaller, keep propagate
            if ((vecTime[node] == -1) || (vecTime[node] > ts)){
                vecTime[node] = ts; 

                // go through all next nodes
                if (checkmap.count(node) != 0){
                    for (auto &vele : checkmap[node]){
                        int next = vele.first; 
                        int weight = vele.second; 

                        bfsqueue.push(make_pair(next, ts+weight)); 
                    }
                }
            }
        }

        // cout << "done2" << endl; 

        // check results: 
        int ret = 0; 
        for (int i = 1; i < (n+1); i++){
            int val = vecTime[i]; 
            if (val == -1) return -1; 
            ret = (ret < val) ? val : ret; 
        }
        return ret; 
    }
};
