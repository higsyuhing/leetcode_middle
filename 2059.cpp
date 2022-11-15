class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // BFS, since we have range [0, 1000], then we will not go infinite. 
        // use a hashmap <num, op> for number num and ops for visiting. 
        // stop expanding if: 
        //  1) num is out of [0,1000], 
        //  2) num is visited before (guaranteed smaller op)

        unordered_map<int, int> visitmap; // <-- 1st improve: map to unordered_map
        visitmap[start] = 0; // since start != goal, this is fine

        queue<int> bfsqueue; // num
        bfsqueue.push(start); 

        while(!bfsqueue.empty()){
            int curr = bfsqueue.front(); 
            bfsqueue.pop(); 

            for (int &num : nums){
                int val[3]; 
                int op = visitmap[curr]; 

                val[0] = curr + num; 
                val[1] = curr - num; 
                val[2] = curr ^ num; 

                for (int i = 0; i < 3; i++){
                    if (val[i] == goal) return (op+1); 
                    if ((visitmap.count(val[i]) == 0) && (val[i] >= 0) && (val[i] <= 1000)){ // <-- 2nd improve: 2 levels if merge to 1
                        visitmap[val[i]] = op + 1; 
                        bfsqueue.push(val[i]); 
                    }
                }
            }
        }

        return -1; 
    }
};
