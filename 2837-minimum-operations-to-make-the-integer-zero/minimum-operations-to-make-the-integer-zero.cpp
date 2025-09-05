#define ll long long

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=36;++i) 
        {
            ll val=(ll)num1-(ll)i*num2;

            if(val<0)
                return -1;
            
            if(__builtin_popcountll(val)<=i && i<=val)
                return i;
        }
        return -1;
    }
};