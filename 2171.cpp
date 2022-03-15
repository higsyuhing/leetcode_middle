class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        // we have an expectation: expect, for the result. 
        // for bag has beans > expect, we remove (beans[i] - expect)
        // for bag has beans < expect, we remove (beans[i])
        // for bag has beans == expect, we remove (0)
        // expect range from 0 to max{beans[i]}
        
        // we can have a map to record the beans number for each bag
        // but how to efficiently search them? I don't want to scan the expect.. 
        // start from expect == 0: 
        //      cost = sum of beans (sum bg*bn). K bags higher than expect
        // for expect from i to i+1: from ki to ki+1
        //      cost += (ki*bni) - ki+1*(bni+1 - bni)
        
        map<int, int> mapbn; 
        long long cost = 0; 
        long long K = 0; // #bags higher than expect
        for(int i = 0; i < beans.size(); i++){
            if(mapbn.find(beans[i]) == mapbn.end()) mapbn[beans[i]] = 1; 
            else mapbn[beans[i]]++; 
            cost += beans[i]; 
            K++; 
        }
        
        int expect = 0; 
        long long result = cost; 
        long long ki = 0; // this does not matter since bn0 = 0 always
        long long bni = 0; 
        
        for(auto it = mapbn.begin(); it != mapbn.end(); it++){
            cost += ((ki*bni) - K*(it->first - bni)); 
            result = (result > cost) ? cost : result; 
            
            ki = it->second; 
            K -= ki; 
            bni = it->first; 
        }
        
        return result; 
    }
};


/*

a better solution! 

https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1766764/C%2B%2BJavaPython3-Sorting-4-lines

*/


