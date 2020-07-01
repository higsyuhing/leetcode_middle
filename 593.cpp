class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // verify all angles are 90? orthogonal? 
        // two vectors <a1, b1> and <a2, b2>, then a1*a2+b1*b2 should be 0. 
        // but I don't know which one is.. 
        // compute all combination distance (without sqrt)
        // thus 4 should be equal and 2 should be 2 times larger than it. 
        // distance <a1, b1> and <a2, b2>, then
        //  (a1 - a2)*2 + (b1 - b2)*2
        
        int d[6]; 
        d[0] = (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]); 
        d[1] = (p1[0] - p3[0])*(p1[0] - p3[0]) + (p1[1] - p3[1])*(p1[1] - p3[1]); 
        d[2] = (p1[0] - p4[0])*(p1[0] - p4[0]) + (p1[1] - p4[1])*(p1[1] - p4[1]); 
        d[3] = (p3[0] - p2[0])*(p3[0] - p2[0]) + (p3[1] - p2[1])*(p3[1] - p2[1]); 
        d[4] = (p4[0] - p2[0])*(p4[0] - p2[0]) + (p4[1] - p2[1])*(p4[1] - p2[1]); 
        d[5] = (p4[0] - p3[0])*(p4[0] - p3[0]) + (p4[1] - p3[1])*(p4[1] - p3[1]); 
        
        map<int, int> verify; 
        for(int i = 0; i < 6; i++){
            if(verify.find(d[i]) == verify.end()){
                verify[d[i]] = 1; 
            }
            else verify[d[i]]++; 
        }
        
        if(verify.size() != 2) return false; 
        
        int small, big; 
        for(auto it=verify.begin(); it!=verify.end(); ++it){
            if(it->second == 4) small = it->first; 
            else if(it->second == 2) big = it->first; 
            else return false; 
        }
        
        if((small << 1) == big) return true; 
        else return false; 
        
    }
};
