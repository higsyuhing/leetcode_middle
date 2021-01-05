class Solution {
public:
    bool isRobotBounded(string instructions) {
        // 2 conditions: 
        // 1. vector length != 0
        // 2. vector direction same as original direction
        
        int deltax, deltay; 
        deltax = 0; deltay = 0; 
        int direction; // 0n, 1s, 2w, 3e
        direction = 0; 
        
        for(int i = 0; i < instructions.size(); i++){
            if(instructions[i] == 'G'){
                switch(direction){
                    case 0: 
                        deltay++; 
                        break; 
                    case 1: 
                        deltay--; 
                        break;
                    case 2: 
                        deltax--; 
                        break; 
                    case 3: 
                        deltax++; 
                        break; 
                    default: 
                        cout << "never happen G\n"; 
                }
            }
            else if(instructions[i] == 'L'){
                switch(direction){
                    case 0: 
                        direction = 2; 
                        break; 
                    case 1: 
                        direction = 3; 
                        break; 
                    case 2: 
                        direction = 1; 
                        break; 
                    case 3: 
                        direction = 0; 
                        break; 
                    default: 
                        cout << "never happen L\n"; 
                }
            }
            else{ // R
                switch(direction){
                    case 0: 
                        direction = 3; 
                        break; 
                    case 1: 
                        direction = 2; 
                        break; 
                    case 2: 
                        direction = 0; 
                        break; 
                    case 3: 
                        direction = 1; 
                        break; 
                    default: 
                        cout << "never happen G\n"; 
                }
            }
            
        }
        
        
        if(((deltax) || (deltay)) && (direction == 0)) return false; 
        return true; 
    }
};
