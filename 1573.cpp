class Solution {
public:
    int numWays(string s) {
        vector<int> list1; 
        int count = 0; 
        int i; 
        for(i = 0; i < s.size(); i++){
            if(s[i] == '1') break; 
        }
        if(i == s.size()){
            unsigned long long length = s.size()%1000000007; 
            return ((length-2)*(length-1)/2)%1000000007; 
        }
        for(i++; i < s.size(); i++){
            if(s[i] == '0') count++; 
            else{
                list1.push_back(count); 
                count = 0; 
            }
        }
        list1.push_back(count); 
        // 00010010001000 -> 1:2, 1:3, 1:3
        if(list1.size() % 3) return 0; 
        
        // 1:2, 1:3, 1:3
        // 0.   1.   2
        // 0/1/2/3/4/5 6: n/3-1, n/3*2-1
        int length = list1.size(); 
        unsigned long long first0, second0; 
        first0 = ((unsigned long long)list1[length/3-1])%1000000007; 
        second0 = ((unsigned long long)list1[2*length/3-1])%1000000007; 
        
        return (first0+1)*(second0+1)%1000000007; 
    }
};
