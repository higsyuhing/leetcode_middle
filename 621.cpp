class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // I feel this is a greedy algo.. 
        
        vector<int> freq; 
        int i; 
        for(i = 0; i < 26; i++) freq.push_back(0); 
        for(i = 0; i < tasks.size(); i++) freq[tasks[i] - 'A']++; 
        sort(freq.begin(), freq.end()); //increasing
        
        int maxval = freq[25] - 1; 
        int idol = maxval*n; 
        for(i = 24; i >= 0; i--){
            if(freq[i] > maxval) idol -= maxval; 
            else idol -= freq[i]; 
        }
        return (idol > 0) ? idol+tasks.size() : tasks.size(); 
    }
};
