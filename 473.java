import java.util.HashMap;

class Solution {

    // The memoization cache to be used during recursion.
    public HashMap<Pair<Integer, Integer>, Boolean> memo;

    // Array containing our matchsticks.
    public int[] nums;

    // Possible side of our square depending on the total sum of all the matchsticks. 
    public int possibleSquareSide;

    // Default constructor to initialise our memo cache.
    public Solution() {
        this.memo = new HashMap<Pair<Integer, Integer>, Boolean>();
    }

    // Main DP function.
    public boolean recurse(Integer mask, Integer sidesDone) {
        int total = 0;
        int L = this.nums.length;

        // The memo key for this recursion
        Pair<Integer, Integer> memoKey = new Pair(mask, sidesDone);

        // Find out the sum of matchsticks used till now.
        for(int i = L - 1; i >= 0; i--) {
            if ((mask&(1 << i)) == 0) {
                total += this.nums[L - 1 - i];
            }
        }

        // If the sum if divisible by our square's side, then we increment our number of complete sides formed variable.
        if (total > 0 && total % this.possibleSquareSide == 0) {
            sidesDone++;
        }

        // Base case.
        if (sidesDone == 3) {
            return true;
        }


        // Return precomputed results
        if (this.memo.containsKey(memoKey)) {
            return this.memo.get(memoKey);
        }

        boolean ans = false;
        int c = total / this.possibleSquareSide;

        // Remaining vlength in the current partially formed side.
        int rem = this.possibleSquareSide * (c + 1) - total;

        // Try out all remaining options (that are valid)
        for(int i = L - 1; i >= 0; i--) {
            if (this.nums[L - 1 - i] <= rem && (mask&(1 << i)) > 0) {
                if (this.recurse(mask ^ (1 << i), sidesDone)) {
                    ans = true;
                    break;
                }
            }
        }

        // Cache the computed results.
        this.memo.put(memoKey, ans);
        return ans;
    }

    public boolean makesquare(int[] nums) {

        // Empty matchsticks.
        if (nums == null || nums.length == 0) {
            return false;
        }

        // Find the perimeter of the square (if at all possible)
        int L = nums.length;
        int perimeter = 0;
        for(int i = 0; i < L; i++) {
            perimeter += nums[i];
        }

        int possibleSquareSide =  perimeter / 4;
        if (possibleSquareSide * 4 != perimeter) {
            return false;
        }

        this.nums = nums;
        this.possibleSquareSide = possibleSquareSide;
        return this.recurse((1 << L) - 1, 0);
    }
}


/*

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        // histogram all matchsticks, and compute the sum of them. 
        // then get the expectation = sum / 4
        // if we greedy apply larger one first, it should work? 
        
        map<int, int> histo; 
        int sum = 0; 
        for(int i = 0; i < matchsticks.size(); i++){
            int curr = matchsticks[i]; 
            if(histo.find(curr) == histo.end()){
                histo[curr] = 1; 
            }
            else{
                histo[curr]++; 
            }
            sum += curr; 
        }
        
        if(sum % 4 != 0) return false; // non-integer always fail
        int expect = sum / 4; 
        
        int space[4]; 
        space[0] = expect; space[1] = expect; space[2] = expect; space[3] = expect; 
        
        map<int, int>::iterator it = histo.end(); 
        it--; 
        
        while(1){
            if(sum == 0) return true; 
            
            // select the largest space. 
            int currindex = 0; int currmaxspace = space[0]; 
            for(int i = 1; i < 4; i++){
                if(space[i] > currmaxspace){
                    currindex = i; 
                    currmaxspace = space[i]; 
                }
            }
            
            currmaxspace = space[currindex]; 
            int key = it->first; 
            
            cout << "space: " << space[0] << " " << space[1] << " "
                << space[2] << " " << space[3] << endl; 
            cout << "select: " << currindex << ", key: " << key << endl; 
            
            if(key > currmaxspace) return false; 
            space[currindex] -= key; 
            sum -= key; 
            histo[key]--; 
            
            if(histo[key] == 0) it--; 
        }
        
    }
};


// OK, when greedy doesn't work, usually it's a DP.. 

*/

