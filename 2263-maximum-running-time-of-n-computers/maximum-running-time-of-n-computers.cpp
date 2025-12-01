#define ll long long

class Solution {
public:

    bool helper(ll mid,int n,vector<int>&batteries)
    {
        ll tar=(ll)n*mid;
        for(int i=0;i<batteries.size();++i)
        {
            tar-=min((ll)batteries[i],mid);
            if(tar<=0)
                return 1;
        }
        return 0;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=LLONG_MAX,r=0;
        for(int i:batteries)
        {
            l=min(l,(ll)i);
            r+=(ll)i;
        }
        r/=n;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(helper(mid,n,batteries))
                l=mid+1;
            else
                r=mid-1;
        }
        return r;
    }
};