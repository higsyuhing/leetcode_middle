class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        // several heuristic rules: 
        // if the length difference is > 1, return false. 
        // if length are the same, only 1 case: replace
        //      check with the difference: head->tail and tail->head
        //      the result should locate on the same spot
        // if length is exactly diff with 1: insert/delete
        //      check with the difference: head->tail and tail->head
        //      the result should locate on the same spot in the longer string
        
        string& slong = (s.size() >= t.size()) ? s : t; 
        string& sshort = (s.size() >= t.size()) ? t : s; 
        if ((slong.size() - sshort.size()) > 1) return false; 
        
        if (sshort.size() == 0){
            if (slong.size() == 0) return false; // both 0
            return true; // exactly 1 diff
        }
        // both size >= 1
        
        // head to tail and tail to head
        int htl, hts, thl, ths; 
        // head / tail / long / short, htl: head-to-tail long string pointer
        htl = 0; hts = 0; thl = slong.size()-1; ths = sshort.size()-1; 
        
        // head to tail check
        for (; hts < sshort.size(); ){
            if (slong[htl] != sshort[hts]) break; 
            htl++; hts++; 
        }
        if (hts == sshort.size()){
            // we reach the end of short string
            // return false if they have the same size: 2 same string
            if (slong.size() == hts) return false; 
            return true; // the last element are diff
        }
        
        // tail to head check
        for (; ths >= 0; ){
            if (slong[thl] != sshort[ths]) break; 
            thl--; ths--; 
        }
        if (ths == -1){
            // we reach the beginning of the short string
            // impossible the same string, return previously
            return true; 
        }
        
        if (htl == thl) return true; 
        return false; 
    }
};

/*

class Solution {
  public boolean isOneEditDistance(String s, String t) {
    int ns = s.length();
    int nt = t.length();

    // Ensure that s is shorter than t.
    if (ns > nt)
      return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance  
    // if the length diff is more than 1.
    if (nt - ns > 1)
      return false;

    for (int i = 0; i < ns; i++)
      if (s.charAt(i) != t.charAt(i))
        // if strings have the same length
        if (ns == nt)
          return s.substring(i + 1).equals(t.substring(i + 1));
        // if strings have different lengths
        else
          return s.substring(i).equals(t.substring(i + 1));

    // If there is no diffs on ns distance
    // the strings are one edit away only if
    // t has one more character. 
    return (ns + 1 == nt);
  }
}

*/
