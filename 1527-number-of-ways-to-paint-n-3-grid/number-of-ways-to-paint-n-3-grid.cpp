#define MOD 1000000007
#define ll long long

class Solution {
public:
    int numOfWays(int n) {
        ll pre=6,cur=6;
        for(int i=2;i<=n;++i)
        {
            ll tA=(pre*3+cur*2)%MOD,tB=(pre*2+cur*2)%MOD;
            pre=tA;
            cur=tB;
        }
        return (pre+cur)%MOD;
    }
};