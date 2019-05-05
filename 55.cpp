class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastindex = nums.size()-1; 
        if(lastindex == -1) return false; 
        if(lastindex == 0) return true; 
        
        // only need to iterate/update the farthest one
        int current = 0; 
        int farthest = 0; 
        int orifarthest = 0; 
        int i, temp; 
        while(1){
            for(i = current; i <= orifarthest; i++){
                temp = i + nums[i]; 
                if(temp > farthest) farthest = temp; 
            }
            
            //printf("%d, %d, %d\n", current, orifarthest, farthest);
            
            if(farthest >= lastindex) return true; 
            if(orifarthest == farthest) break; 
            current = orifarthest; 
            orifarthest = farthest; 
        }
        
        return false; 
        
        
        /*
        //I see execllent answer in sol.. 
        
        int lastPos = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
        
        
        */
        
        
        /*
        // version 1 with time limit
        
        int lastindex = nums.size()-1; 
        if(lastindex == -1) return false; 
        if(lastindex == 0) return true; 
        
        //maintain a queue to preserve the array index
        queue<int> indexqueue;
        indexqueue.push(0);
        //a hashmap to check if the index is already in queue
        map<int, bool> indexmap; 
        indexmap[0] = true; 
        
        int currindex, stepval, tempindex; 
        map<int, bool>::iterator it;
        while(indexqueue.size()){
            //get the first one and earse from queue and map
            currindex = indexqueue.front();
            indexqueue.pop(); 
            it = indexmap.find(currindex); 
            if(it != indexmap.end()) indexmap.erase(it);
            else{
                cout << "Fatal error! " << endl; 
                return false; 
            }
            
            stepval = nums[currindex]; 
            for(tempindex = currindex+1; tempindex < (currindex+stepval+1); tempindex++){
                //must continuous.. 
                if(tempindex == lastindex) return true; 
                
                it = indexmap.find(tempindex); 
                if(it == indexmap.end()){
                    indexmap[tempindex] = true; 
                    indexqueue.push(tempindex);
                }
            }
        }
        return false; 
        */
    }
};
