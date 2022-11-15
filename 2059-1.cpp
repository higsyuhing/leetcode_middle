class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // BFS, since we have range [0, 1000], then we will not go infinite. 
        // use a hashmap <num, op> for number num and ops for visiting. 
        // stop expanding if: 
        //  1) num is out of [0,1000], 
        //  2) num is visited before (guaranteed smaller op)

        int visitmap[1001]; 
        for (int i = 0; i < 1001; i++) visitmap[i] = -1; // <-- since the hash has const size, use array instead
        visitmap[start] = 0; // since start != goal, this is fine

        queue<int> bfsqueue; // num
        bfsqueue.push(start); 

        // int debug_count = 0; 
        // cout << nums.size() << endl; 

        while(!bfsqueue.empty()){
            int curr = bfsqueue.front(); 
            bfsqueue.pop(); 

            for (int &num : nums){
                int val1, val2, val3; 
                int op = visitmap[curr]; 

                val1 = curr + num; 
                val2 = curr - num; 
                val3 = curr ^ num; 
                // debug_count++; 

                // for (int i = 0; i < 3; i++){
                //     if (val[i] == goal){
                //         // cout << debug_count << endl; 
                //         return (op+1); 
                //     }
                //     if ((val[i] >= 0) && (val[i] <= 1000) && (visitmap[val[i]] == -1)){
                //         visitmap[val[i]] = op + 1; 
                //         bfsqueue.push(val[i]); 
                //     }
                // }
                
                // <-- loop unrolling for better perf. 

                if (val1 == goal){
                    // cout << debug_count << endl; 
                    return (op+1); 
                }
                if ((val1 >= 0) && (val1 <= 1000) && (visitmap[val1] == -1)){
                    visitmap[val1] = op + 1; 
                    bfsqueue.push(val1); 
                }

                if (val2 == goal){
                    // cout << debug_count << endl; 
                    return (op+1); 
                }
                if ((val2 >= 0) && (val2 <= 1000) && (visitmap[val2] == -1)){
                    visitmap[val2] = op + 1; 
                    bfsqueue.push(val2); 
                }

                if (val3 == goal){
                    // cout << debug_count << endl; 
                    return (op+1); 
                }
                if ((val3 >= 0) && (val3 <= 1000) && (visitmap[val3] == -1)){
                    visitmap[val3] = op + 1; 
                    bfsqueue.push(val3); 
                }

            }
        }

        return -1; 
    }
};
