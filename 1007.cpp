class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        // 3 cases: 0,1,2 solution.. if we have 2 sol, each one is same
        int hypo1, hypo2, hypo; 
        int len = A.size(); 
        int i, tempa, tempb; 
        hypo = 0; 
        hypo1 = 0; 
        
        // corner case.. for len == 1..... 
        if(len == 1) return 0; 
        
        // find hypo
        for(i = 0; i < len; i++){
            tempa = A[i]; tempb = B[i]; 
            // if they are same, only way is hypo this number
            if(tempa == tempb){
                hypo = tempa; 
                break; 
            }
            // if they are different, if hypo not set, set hypo1/2
            if(hypo1 == 0){
                hypo1 = tempa; 
                hypo2 = tempb; 
                continue; 
            }
            // if set hypo, but same as hypo1/2, continue
            if((hypo1 == tempa) && (hypo2 == tempb)) continue; 
            if((hypo1 == tempb) && (hypo2 == tempa)) continue; 
            
            if((hypo1 == tempa) || (hypo2 == tempa)){
                hypo = tempa; 
                break; 
            }
            if((hypo1 == tempb) || (hypo2 == tempb)){
                hypo = tempb; 
                break; 
            }
            return -1; 
        }
        //cout << "hypo: " << hypo << endl; 
        
        // find minimum rotate
        int roa = 0; 
        int rob = 0; 
        for(i = 0; i < len; i++){
            tempa = A[i]; tempb = B[i]; 
            
            // the i after deciding hypo
            if((tempa != hypo) && (tempb != hypo)) return -1; 
            
            if(tempa != hypo) roa++; 
            if(tempb != hypo) rob++; 
        }
        //cout << "roa:" << roa << "; rob:" << rob << endl; 
        
        return (roa > rob) ? rob : roa; 
    }
};
