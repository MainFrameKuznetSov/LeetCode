#define ll long long
class Solution {
public:

    int MOD=1e9+7;

    ll exp(ll a,ll b)
    {
        ll ans=1;
        while(b)
        {
            if(b&1)
                ans=(ans*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        ll ev=(n+1)/2,odd=n/2;
        ll ans=(exp(5,ev)*exp(4,odd))%MOD;
        return ans;
    }
};