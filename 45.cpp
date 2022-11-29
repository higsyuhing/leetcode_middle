class Solution {
public:
    int jump(vector<int>& nums) {
        // BFS. 
        // use a same length array as a visited/#step array
        // init with -1, and labeled when we arrived. 
        if (nums.size() == 1) return 0; 
        vector<int> steps(nums.size(), -1); 

        queue<int> indexqueue; 
        indexqueue.push(0); 
        int currstep = 0; 
        indexqueue.push(-1); // end of currstep label

        while (indexqueue.size() > 1){ // only "end of currstep" label
            int curr = indexqueue.front(); 
            indexqueue.pop(); 
            // cout << "while: " << curr << endl; 

            if (curr == -1){
                indexqueue.push(-1); 
                currstep++; 
                continue; 
            }
            if (steps[curr] != -1){ // already visited, not search this branch
                continue; 
            }
            steps[curr] = currstep; 
            // cout << currstep << endl; 

            // check all next indexes
            for (int i = 1; i <= nums[curr]; i++){
                // but usually we will reach the end first.. 
                // if ((curr + i) == nums.size()){ 
                //     break; 
                // }
                int nextindex = curr + i; 
                if (nextindex == (nums.size()-1)){
                    return (currstep+1); 
                }
                indexqueue.push(nextindex); 
            }
        }

        // never reach here.. 
        return -1; 
    }
};

/*
this can be improved with greedy bfs. 
https://leetcode.com/problems/jump-game-ii/solutions/1192401/easy-solutions-w-explanation-optimizations-from-brute-force-to-dp-to-greedy-bfs/

*/
