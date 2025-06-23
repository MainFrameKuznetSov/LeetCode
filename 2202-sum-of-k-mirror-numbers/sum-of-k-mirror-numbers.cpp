#define ll long long
class Solution {
public:

    ll helper(ll n,bool f)
    {
        ll temp=n;
        if(f)
            temp/=10;
        while(temp)
        {
            n=(n*10)+(temp%10);
            temp/=10;
        }
        return n;
    }

    bool isPalin(ll n,int base)
    {
        vector<int>dig;
        while(n)
        {
            dig.push_back(n%base);
            n/=base;
        }
        int l=0,r=dig.size()-1;
        while(l<r)
        {
            if(dig[l]!=dig[r])
                return 0;
            ++l;
            --r;
        }
        return 1;
    }

    long long kMirror(int k, int n) {
        ll ans=0;
        for(ll i=1;n;i*=10)
        {
            for(ll j=i;n && j<i*10;++j)
            {
                ll temp=helper(j,1);
                if(isPalin(temp,k))
                {
                    ans+=temp;
                    --n;
                }
            }
            for(ll j=i;n && j<i*10;++j)
            {
                ll temp=helper(j,0);
                if(isPalin(temp,k))
                {
                    ans+=temp;
                    --n;
                }
            }
        }
        return ans;
    }
};