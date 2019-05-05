class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret; 
        
        //define direction: 
        //0:east; 1:south; 2:west; 3:north
        int direction = 0; 
        
        //define boundaries, 
        //available index: p <= x <=q
        int northrow, southrow, eastcol, westcol; 
        northrow = 0; 
        westcol = 0; 
        southrow = matrix.size()-1; 
        if(southrow == -1) return ret; 
        vector<vector<int>>::iterator it = matrix.begin();
        eastcol = it->size()-1; 
        if(eastcol == -1) return ret; 
        
        //printf("boundaries: %d, %d\n", southrow, eastcol);
        int i; 
        while(1){
            if((northrow > southrow) || (westcol > eastcol)) break; 
            switch(direction){
                case 0: 
                    for(i = westcol; i <= eastcol; i++){
                        ret.push_back(matrix[northrow][i]); 
                    }
                    northrow++; 
                    break; 
                case 1: 
                    for(i = northrow; i <= southrow; i++){
                        ret.push_back(matrix[i][eastcol]); 
                    }
                    eastcol--; 
                    break; 
                case 2: 
                    for(i = eastcol; i >= westcol; i--){
                        ret.push_back(matrix[southrow][i]); 
                    }
                    southrow--; 
                    break; 
                case 3: 
                    for(i = southrow; i >= northrow; i--){
                        ret.push_back(matrix[i][westcol]); 
                    }
                    westcol++; 
                    break; 
                default: 
                    break; 
            }
            direction++; 
            if(direction == 4) direction = 0; 
        }
        
        return ret; 
    }
};
