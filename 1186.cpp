class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // max sum end with i-th, 2 memories w/wo deletion
        // a_w[i+1] = max{a_w[i]+arr[i], a_wo[i]}
        // a_wo[i+1] = max{a_wo[i]+arr[i], arr[i]}
        
        if(arr.size() == 0) return 0; 
        
        vector<int> a_w, a_wo; 
        a_w.reserve(arr.size()); 
        a_wo.reserve(arr.size()); 
        
        a_wo[0] = arr[0]; 
        a_w[0] = 0; 
        
        //cout << "0: " << a_w[0] << " " << a_wo[0] << endl; 
        int maxsum = arr[0]; 
        for(int i = 0; i < (arr.size()-1); i++){
            a_w[i+1] = ((a_w[i]+arr[i+1]) > a_wo[i]) ? (a_w[i]+arr[i+1]) : a_wo[i]; 
            a_wo[i+1] = ((a_wo[i]+arr[i+1]) > arr[i+1]) ? (a_wo[i]+arr[i+1]) : arr[i+1]; 
            
            //cout << i+1 << ": " << a_w[i+1] << " " << a_wo[i+1] << endl; 
            //cout << (a_wo[i]+arr[i]) << endl; 
            
            maxsum = (a_w[i+1] > maxsum) ? a_w[i+1] : maxsum; 
            maxsum = (a_wo[i+1] > maxsum) ? a_wo[i+1] : maxsum; 
        }
        
        return maxsum; 
    }
};
