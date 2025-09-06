
#define ll long long
#define lloop(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        ll ans=0LL;
        for(auto it:queries)
        {
            ll left=it[0],right=it[1],sum=0LL,pwr=1LL;
            lloop(j,1,15)
            {
                ll low=pwr,high=pwr*4-1;
                ll lb=max(left,low),ub=min(right,high);
                if(lb<=ub)
                {
                    ll gap=ub-lb+1;
                    sum+=(ll)(gap*j);
                }
                pwr*=4;
            }
            ans+=(ll)ceil((double)sum/2);
        }
        return ans;
    }
};