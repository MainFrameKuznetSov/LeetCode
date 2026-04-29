#define ll long long

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)
            return 0;
        vector<ll>pre(n+1,0),cur(n+1,0);
        for(int i=1;i<n;++i)
        {
            vector<ll>npre(n+1,0),ncur(n+1,0);
            for(int j=0;j<=n;++j)
            {
                ll f=0,s=0;
                for(int k=0;k<j;++k)
                    s+=grid[k][i];
                for(int l=0;l<=n;++l)
                {
                    if(l>0 && l<=j)
                    s-=grid[l-1][i];
                    if(l>j)
                        f+=grid[l-1][i-1];
                    npre[l]=max({npre[l],f+pre[j],cur[j]});
                    ncur[l]=max({ncur[l],s+cur[j],s+f+pre[j]});
                }
            }
            pre=npre;
            cur=ncur;
        }
        ll ans=0;
        for(ll i:cur)
            ans=max(ans,i);
        return ans;
    }
};