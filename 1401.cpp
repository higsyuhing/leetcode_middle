class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // 2 cases: for circle center
        // 1. exactly left/right/up/down of rect
        // 2. outside corners of rect
        //      <2> #2      \      <1> #8     \      <2> #5
        //                  \                 \
        // - - - - - - - -  ------------------- - - - - - - - - 
        //                  |                 |
        //      <1> #3      |      rect       |      <1> #6
        // - - - - - - - -  ------------------- - - - - - - - - 
        //                  \                 \
        //      <2> #1      \      <1> #7     \      <2> #4
        // case 1 compare direct distance
        // case 2 compare radius with corner distance
        
        // if circle center is in rect, return true
        if((x_center >= x1) && (y_center >= y1) && (x_center <= x2) && (y_center <= y2)) return true; 
        
        // left 3
        if(x_center < x1){
            if(y_center < y1){
                // case #1
                int dist = (x1-x_center)*(x1-x_center)+(y1-y_center)*(y1-y_center); 
                if(dist <= (radius*radius)) return true; 
                else return false;
            }
            if(y_center > y2){
                // case #2
                int dist = (x1-x_center)*(x1-x_center)+(y2-y_center)*(y2-y_center); 
                if(dist <= (radius*radius)) return true; 
                else return false;
            }
            // case #3
            if((x1-x_center) <= radius) return true; 
            else return false; 
        }
        
        // right 3
        if(x_center > x2){
            if(y_center < y1){
                // case #4
                int dist = (x2-x_center)*(x2-x_center)+(y1-y_center)*(y1-y_center); 
                if(dist <= (radius*radius)) return true; 
                else return false;
            }
            if(y_center > y2){
                // case #5
                int dist = (x2-x_center)*(x2-x_center)+(y2-y_center)*(y2-y_center); 
                if(dist <= (radius*radius)) return true; 
                else return false;
            }
            // case #6
            if((x_center-x2) <= radius) return true; 
            else return false; 
        }
        
        // down #7
        if(y_center < y1){
            if((y1-y_center) <= radius) return true; 
            else return false; 
        }
        
        // up #8
        if(y_center > y2){
            if((y_center-y2) <= radius) return true; 
            else return false; 
        }
        
        cout << "never here case.. \n"; 
        return false; 
    }
};

// check this solution, amazing! 
// https://leetcode.com/problems/circle-and-rectangle-overlapping/discuss/563463/C%2B%2B-with-simple-explanation
