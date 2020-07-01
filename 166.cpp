class Solution {
public:
    string fractionToDecimal(long num, long den, string frac="",int count=1) 
    {
        const auto sign = (num<0) ^ (den<0);
        num = abs(num),den=abs(den);
        long rem = num%den;
        unordered_map<int,int> vis{{(int)rem,0}};
        string ans = (sign ? "-"+to_string(num/den) : to_string(num/den));
        while(rem)
        {
            rem*=10;
            frac.append(to_string(rem/den));
            rem%=den;
            if(vis.count(rem))
                return ans + "."+ frac.substr(0,vis[rem]) + "("+frac.substr(vis[rem])+")";
            
            vis.insert({rem,count++});
        }
        return num==0 ? "0" : (frac.empty() ? ans : ans+"."+frac);
    }
};

/*
with default arguemnt.. hmmm..
*/
