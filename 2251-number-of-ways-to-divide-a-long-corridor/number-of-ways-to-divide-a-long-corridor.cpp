#define MOD (int)(1e9+7)
#define ll long long

class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size(),cnt=0;
        for(char c:corridor)
        {
            if(c=='S')
                ++cnt;
        }
        if(cnt==0 || cnt&1)
            return 0;
        cnt=0;
        ll ans=1LL;
        int i=0,j=0;
        bool f=0;
        while(i<n)
        {
            if(corridor[i]=='S')
            {
                ++cnt;
                if(cnt%2==0)
                    f=1;
                else if(cnt>2)
                {
                    ans=(ans*(j+1))%MOD;
                    cnt=1;
                    f=0;
                    j=0;
                }
            }
            else if(f)
                ++j;
            ++i;
        }        
        return (int)(ans%MOD);
    }
};