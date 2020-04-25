class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // use 2D map for table info
        // once detected solution, start pruning..  
        // use "-1" for many places
        
        unordered_map<int, unordered_map<int, int> > pricetab;
        unordered_map<int, int> minmap; 
        int i; 
        for(i = 0; i < flights.size(); i++){
            pricetab[flights[i][0]][flights[i][1]] = flights[i][2]; 
        }
        
        queue<int> bfsqueue, bfsaccu; // one for curr pos, one for price sum
        bfsqueue.push(src); 
        bfsaccu.push(0); 
        bfsqueue.push(-1); 
        bfsaccu.push(0); 
        int curr, currprice, temp, temp1, temp2; 
        minmap[src] = 0; 
        
        
        while(1){
            curr = bfsqueue.front(); 
            bfsqueue.pop(); 
            currprice = bfsaccu.front(); 
            bfsaccu.pop(); 
            
            if(curr == -1){
                if(K == 0) break; 
                K--; 
                bfsqueue.push(-1); 
                bfsaccu.push(0); 
                continue; 
            }
            
            if(pricetab.find(curr) == pricetab.end()) continue; 
            
            // check if we can find target
            if(pricetab[curr].find(dst) != pricetab[curr].end()){
                temp = currprice + pricetab[curr][dst]; 
                if((minmap.find(dst) == minmap.end()) || minmap[dst] > temp) 
                    minmap[dst] = temp; 
            }
            
            for(auto it = pricetab[curr].begin(); it != pricetab[curr].end(); it++){
                temp1 = it->first; 
                temp2 = it->second; 
                
                if(temp1 == dst) continue; 
                
                temp = currprice + temp2; 
                if((minmap.find(dst) == minmap.end()) || minmap[dst] > temp){
                    if((minmap.find(temp1)==minmap.end()) || minmap[temp1]>temp){
                        minmap[temp1] = temp; 
                        bfsqueue.push(temp1); 
                        bfsaccu.push(temp); 
                        continue; 
                    }
                }
            }
        }
        
        return (minmap.find(dst) == minmap.end()) ? -1 : minmap[dst]; 
    }
};
