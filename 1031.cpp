class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        // max Sum with firstLen, using a sliding window. 
        // look left [firstLen, end] and look right [0, end-firstLen]
        // then given a secondLen, sliding through
        // given [i, i+secondLen]: if i >= firstLen, look left; 
        //  if i+secondLen <= end-firstLen, look right; else skip

        int len = nums.size(); 
        vector<int> lookleft(len+1, -1); 
        vector<int> lookright(len+1, -1); 
        int swval = 0; 
        int maxval = 0; 

        for (int i = 0; i < firstLen; i++){
            swval += nums[i]; 
        }
        for (int i = firstLen; i < len; i++){
            maxval = (maxval < swval) ? swval : maxval; 
            lookleft[i] = maxval; 
            swval -= nums[i - firstLen]; 
            swval += nums[i]; 
        }

        swval = 0; 
        maxval = 0; 
        for (int i = 0; i < firstLen; i++){
            swval += nums[len-1-i]; 
        }
        for (int i = firstLen; i < len; i++){
            maxval = (maxval < swval) ? swval : maxval; 
            lookright[len - 1 - i] = maxval; 
            swval -= nums[len-1-i+firstLen]; 
            swval += nums[len-1-i]; 
        }

        // debug
        // cout << "lookleft: " << endl; 
        // for (int val : lookleft){
        //     cout << val << ", "; 
        // }
        // cout << endl; 
        // cout << "lookright: " << endl; 
        // for (int val : lookright){
        //     cout << val << ", "; 
        // }
        // cout << endl; 

        // note that both lookleft and lookright are non-included index: 
        // stand at index i and look left, we are not count index i itself

        swval = 0; 
        maxval = 0; 
        int tmpval1, tmpval2; 
        for (int i = 0; i < secondLen; i++){
            swval += nums[i]; 
        }
        for (int i = secondLen; i < len; i++){
            tmpval1 = -1; 
            tmpval2 = -1; 
            if ((i-secondLen) >= firstLen){
                tmpval1 = swval + lookleft[i-secondLen]; 
            }
            if ((len-i) >= firstLen){
                tmpval2 = swval + lookright[i-1]; 
            }
            // cout << swval << ": " << tmpval1 << ", " << tmpval2 << endl; 
            tmpval1 = (tmpval1 > tmpval2) ? tmpval1 : tmpval2; 
            if (tmpval1 != -1){
                maxval = (maxval < tmpval1) ? tmpval1 : maxval; 
            }

            swval -= nums[i - secondLen]; 
            swval += nums[i]; 
        }
        // the end one.. guarantee valid
        tmpval1 = swval + lookleft[len-secondLen]; 
        maxval = (maxval < tmpval1) ? tmpval1 : maxval; 

        return maxval; 
    }
};
