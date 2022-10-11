class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // improved one, represent with hashmap
        // encode number with bits: 000 001 ... 111: "left|middle|right"
        // 1 means has seat (true), 0 means reserved (false)
        
        map<int, int> reservemap; 
        
        for (auto seat : reservedSeats){
            int rn = seat[0]-1; 
            int cn = seat[1]; 
            
            // ignored case
            if (cn == 1 || cn == 10)
                continue; 
            
            if (reservemap.find(rn) == reservemap.end())
                reservemap[rn] = 7; // 111, init with having seats
            
            // we definitely will eliminate some seats
            // i.e. any element in reservemap will never be 7. 
            // due to the ignored case
            
            if (cn >= 2 && cn <= 5)
                reservemap[rn] = reservemap[rn] & 3; // 011
            if (cn >= 4 && cn <= 7)
                reservemap[rn] = reservemap[rn] & 5; // 101
            if (cn >= 6 && cn <= 9)
                reservemap[rn] = reservemap[rn] & 6; // 110
        }
        
        /*
        int res = 0; 
        for (int i = 0; i < n; i++){
            if (reservemap.find(i) == reservemap.end())
                res += 2; 
            else if (reservemap[i] != 0)
                res += 1; 
        }
        */
        
        // use minus to speed up, we don't care the row number.. 
        int res = n*2; 
        for (auto ele : reservemap){
            res = (ele.second == 0) ? (res - 2) : (res - 1); 
        }
        
        return res; 
    }
};

/*

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // greedy on 2-2 aisle split case. 
        // n rows and 3 columns: left, middle, right; checking: 
        //      2-5; 4-7; 6-9
        
        auto arr2d = new int [n][3]; 
        for (int i = 0; i < n; i++){
            arr2d[i][0] = 1; 
            arr2d[i][1] = 1; 
            arr2d[i][2] = 1; 
        }
        
        for (auto seat : reservedSeats){
            int rn = seat[0]; 
            int cn = seat[1]; 
            
            if (cn >= 2 && cn <= 5)
                arr2d[rn-1][0] = 0; 
            if (cn >= 4 && cn <= 7)
                arr2d[rn-1][1] = 0; 
            if (cn >= 6 && cn <= 9)
                arr2d[rn-1][2] = 0; 
        }
        
        int res = 0; 
        for (int i = 0; i < n; i++){
            // cout << arr2d[i][0] << ", " << arr2d[i][1] << ", " << arr2d[i][2] << endl; 
            
            if (arr2d[i][0] == 1 && arr2d[i][2] == 1)
                res += 2; 
            else if ((arr2d[i][0] + arr2d[i][1] + arr2d[i][2]) != 0)
                res += 1; 
        }
        delete [] arr2d; 
        
        return res; 
    }
};



*/
