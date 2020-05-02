class Solution {
public:
    int count; 
    int len; 
    
    void permute(vector<int>& array, int pos){
        if(pos == len){
            count++; 
            return; 
        }
        for(int i = pos; i < len; i++){
            int temp; 
            temp = array[i]; 
            array[i] = array[pos]; 
            array[pos] = temp; 
            
            if(array[pos] % (pos+1) == 0 || (pos+1) % array[pos] == 0)
                permute(array, pos+1); 
            
            temp = array[i]; 
            array[i] = array[pos]; 
            array[pos] = temp; 
        }
    }
    
    int countArrangement(int N) {
        // for a given N, this is a DP? 
        // or a recrusive search? but I feel not efficient.. some math trick here
        // induction? N = 1, N = 2 .. 
        
        // induction: given solution for N, N+1 will be: 
        // {N}, N+1; swap all cases in N with N+1 and see
        // not good still.. 
        
        // cpp version of sol 2..
        
        vector<int> array(N); 
        count = 0; 
        len = N; 
        for(int i = 0; i < N; i++) array[i] = i+1; 
        
        permute(array, 0); 
        return count; 
    }
};
