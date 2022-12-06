class Solution {
public:


    string longestDiverseString(int a, int b, int c) {
        // x >= y >= z, if x > (y+z+1)*2, then we need to give up some x
        if (a == 0 && b == 0 && c == 0)
            return ""; 
        string cx, cy, cz; 
        int x, y, z; 

        cx = "a"; cy = "b"; cz = "c"; 
        x = a; y = b; z = c; 
        if (x < y){
            swap(x, y); 
            swap(cx, cy); 
        }
        if (x < z){
            swap(x, z); 
            swap(cx, cz); 
        }
        if (y < z){
            swap(y, z); 
            swap(cy, cz); 
        }

        // cout << x << "-" << cx << ", " << y << "-" << cy << ", " << z << "-" << cz << endl; 

        // I feel Jamie's idea is better.. 
        if (x >= ((y+z+1)*2)){
            string ret; 
            ret += (cx + cx); 
            while ((y+z) > 0){
                if (y > 0){
                    ret += cy; 
                    y--; 
                }
                else{
                    ret += cz; 
                    z--; 
                }
                ret += (cx + cx); 
            }
            return ret; 
        }

        vector<string> array; 
        while (x >= 2){
            array.push_back(cx + cx); 
            x -= 2; 
        }
        if (x > 0){
            array.push_back(cx); 
        }

        int i; 
        for (i = 0; i < array.size(); i++){
            if (y == 0)
                break; 
            array[i] += cy; 
            y--; 
        }
        if (y > 0){
            for (i = 0; i < array.size(); i++){
                if (y == 0)
                    break; 
                array[i] += cy; 
                y--; 
            }
        }
        for (; i < array.size(); i++){
            if (z == 0)
                break; 
            array[i] += cz; 
            z--; 
        }
        for (i = 0; i < array.size(); i++){
            if (z == 0)
                break; 
            array[i] += cz; 
            z--; 
        }
        for (i = 0; i < array.size(); i++){
            if (z == 0)
                break; 
            array[i] += cz; 
            z--; 
        }

        string ret; 
        for (string &curr : array){
            ret += curr; 
        }
        return ret; 


        // string ret; 
        // while (x < ((y+z+1)*2)){
        //     // if y == 0, z must be 0, then we will never come here (x > (..))
        //     // if x == 0, then y=z=0, never be here.. 
        //     if (x%2 == 1){
        //         ret += cx; 
        //         x--; 
        //         ret += cy; 
        //         y--; 
        //     }
        //     else{

        //     }

        // }
        // if (x == 0){
        //     return ret; 
        // }

        // ret += (cx + cx); 
        // while ((y+z) > 0){
        //     if (y > 0){
        //         ret += cy; 
        //         y--; 
        //     }
        //     else{
        //         ret += cz; 
        //         z--; 
        //     }
        //     ret += (cx + cx); 
        // }
        // return ret; 
    }
};

/*
https://leetcode.com/problems/longest-happy-string/solutions/564277/c-java-a-b-c/?orderBy=most_votes
*/
