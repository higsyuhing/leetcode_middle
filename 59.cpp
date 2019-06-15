class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i, j, north, south, east, west, val; 
        vector<vector<int>> ret; 
        
        if(n < 1) return ret; 
        
        for(i = 0; i < n; i++){
            vector<int> tempvec; 
            for(j = 0; j < n; j++){
                tempvec.push_back(i); 
            }
            ret.push_back(tempvec); 
        }
        
        north = 0; west = 0; east = n, south = n; 
        val = 0; 
        while(1){
            if(west < east){
                i = north; 
                for(j = west; j < east; j++){
                    val++; 
                    ret[i][j] = val; 
                }
                north++; 
            }
            else break; 
            
            if(north < south){
                j = east-1; 
                for(i = north; i < south; i++){
                    val++; 
                    ret[i][j] = val; 
                }
                east--; 
            }
            else break; 
            
            if(west < east){
                i = south-1; 
                for(j = east - 1; j >= west; j--){
                    val++; 
                    ret[i][j] = val; 
                }
                south--; 
            }
            else break; 
            
            if(north < south){
                j = west; 
                for(i = south - 1; i >= north; i--){
                    val++; 
                    ret[i][j] = val; 
                }
                west++; 
            }
            else break; 
        }
        
        return ret; 
    }
};
