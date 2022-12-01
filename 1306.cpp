class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // BFS.. with a visited label
        vector<bool> visited(arr.size(), false); // true visited
        queue<int> bfsqueue; 
        bfsqueue.push(start); // no need for step separator

        while (bfsqueue.size() > 0){
            int curr = bfsqueue.front(); 
            bfsqueue.pop(); 

            if (arr[curr] == 0)
                return true; 
            
            visited[curr] = true; 
            if (((curr - arr[curr]) >= 0) && (visited[curr - arr[curr]] == false))
                bfsqueue.push(curr - arr[curr]); 
            if (((curr + arr[curr]) < arr.size()) && (visited[curr + arr[curr]] == false))
                bfsqueue.push(curr + arr[curr]); 
        }

        return false; 
    }
};
