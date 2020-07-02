class Solution {
    public int maximumSwap(int num) {
        char[] A = Integer.toString(num).toCharArray();
        int[] last = new int[10];
        for (int i = 0; i < A.length; i++) {
            last[A[i] - '0'] = i;
        }

        for (int i = 0; i < A.length; i++) {
            for (int d = 9; d > A[i] - '0'; d--) {
                if (last[d] > i) {
                    char tmp = A[i];
                    A[i] = A[last[d]];
                    A[last[d]] = tmp;
                    return Integer.valueOf(new String(A));
                }
            }
        }
        return num;
    }
}

/*

class Solution {
public:
    int maximumSwap(int num) {
        // int to int array.. 
        // keep record: 1. if decrease order, 2. largest number/pos
        // if 1. yes dec order, then return
        // else swap the header with the largest number/pos
        
        if(num == 0) return 0; 
        
        int record[32]; 
        int decorder = 1; 
        int pos, maxnum, maxpos, temp, curr, last; 
        temp = num; 
        
        maxnum = num%10; 
        maxpos = 0; // maxnum * 10^maxpos
        last = -1; 
        pos = 0; 
        while(temp){
            curr = temp%10; 
            if(curr > maxnum){
                maxnum = curr; 
                maxpos = pos; 
            }
            if(decorder){
                if(last > curr) decorder = 0; 
            }
            last = curr; 
            record[pos] = curr; 
            pos++; 
            temp = temp/10; 
        }
        
        if(decorder) return num; 
        
        for(int i = pos-1; i > maxpos; i--){
            if(record[i] < maxnum){
                temp = record[i]; 
                record[i] = maxnum; 
                record[maxpos] = temp; 
                
                int ret = 0; 
                for(int j = pos - 1; j >= 0; j--){
                    ret *= 10; 
                    ret += record[j]; 
                }
                return ret; 
            }
        }
        // find the next maximum.. oh no.. 
        
        
        
        
        
        
        
        
        curr = num; 
        for(last = 0; last < pos; last++){
            curr = curr/10; 
            
        }
        
        
        
    }
};

*/
