#define ll long long
#define MOD 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans=0;
        int bits=0;
        for(int i=1;i<=n;++i)
        {
            if((i&(i-1))==0)
                ++bits;
            ans=((ans<<bits)|i)%MOD;
        }
        return ans;
    }
};