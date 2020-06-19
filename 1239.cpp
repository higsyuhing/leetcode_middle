class Solution {
public:
    int inner_recursive(vector<int>& hasharr, vector<string>& arr, 
                        int curr, int n, int base){
        // hasharr: all hashs; arr: all strings for length
        // curr: current position, to n: [curr, n)
        // base: previous masks
        if(curr == n) return 0; 
        int i, tempmax, ret; 
        tempmax = 0; // if no one matches, returns 0. 
        for(i = curr; i < n; i++){
            if(hasharr[i] == -1) continue; 
            if(!(base & hasharr[i])){
                ret = inner_recursive(hasharr, arr, i+1, n, base | hasharr[i]); 
                ret += arr[i].size(); 
                tempmax = (tempmax > ret) ? tempmax : ret; 
            }
        }
        return tempmax; 
    }
    
    
    int maxLength(vector<string>& arr) {
        // you will have a DFS.. 
        // have a vector and do recursive.. 
        
        int n=arr.size(),i,j;
        vector<int> hasharr(n,0);
        for(i=0;i<n;i++)
        {
            string str=arr[i];
            int bitwise=0;
            int bitwisepre = 0; 
            int flag = 0; // for repeat chars.. 
            for(j=0;j<str.size();j++)
            {
                int bit_idx=str[j]-'a';
                bitwise=bitwise|(1<<bit_idx);
                if(bitwisepre == bitwise){
                    flag = 1; 
                    break; 
                }
                bitwisepre = bitwise; 
            }
            if(flag) hasharr[i] = -1; 
            else hasharr[i]=bitwise;
        }
        
        return inner_recursive(hasharr, arr, 0, n, 0);
    }
};
