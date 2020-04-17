class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        // measure the "incremental" of X interval and if(grumpy[i]==1)
        // then compute the maximum of the starting point interval
        // also measure the base satisfication. 
        
        int len = customers.size(); 
        if(len == 0) return 0; 
        // start: start of X, "end": start+X, sum: incremental satisfication
        // max: current max incremental, total: base satisfication
        int start, sum, max, total, i; 
        
        start = 0; sum = 0; total = 0; 
        for(i = 0; i < X; i++){
            if(i < len) sum += customers[i]*grumpy[i]; //add angry case
        }
        max = sum; 
        if(grumpy[0] == 0) total += customers[0]; 
        //cout << "max init: " << max << endl; 
        
        for(start = 1; start < len; start++){
            if(grumpy[start] == 0) total += customers[start]; 
            
            sum -= customers[start-1]*grumpy[start-1];
            if((start+X-1) < len) sum+= customers[start+X-1]*grumpy[start+X-1];
            //cout << "start: " << start << " , sum: " << sum << endl; 
            
            if(sum > max){
                max = sum; 
                //cout << "max updated: " << start << " , max: " << max << endl; 
            } 
        }
        
        return (total+max); 
        
    }
};
