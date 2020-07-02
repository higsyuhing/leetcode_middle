class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)
            return false;
        
        if(x==0&&y==0)
        {
            if(z==0)
                return true;
            return false;
        }
        
        if(x==0)
        {
            if(y==z||z==0)
                return true;
            return false;
        }
        if(y==0)
        {
            if(x==z||z==0)
                return true;
            return false;
        }
            
        
        if(x+y==z)
            return true;
        int val=(x<=y)?gcd(x,y%x):gcd(y,x%y);
        // System.out.println(val);
        if(z%val==0)
            return true;
        
        return false;
    }
    
private: 
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
};
