#define ll long long

class Solution {
public:

    ll f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        ll mn=INT_MAX;
        for(int k=i;k<=j;++k)
        {
            ll cost=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mn=min(mn,cost);
        }
        return dp[i][j]=mn;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        n=cuts.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //return f(1,n-2,cuts,dp);
        for(int i=n-2;i>=1;--i)
        {
            for(int j=1;j<=n-2;++j)
            {
                if(i>j)
                    continue;
                ll mn=INT_MAX;
                for(int k=i;k<=j;++k)
                {
                    ll cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mn=min(mn,cost);
                }
                dp[i][j]=mn;
            }
        }
        return dp[1][n-2];
    }
};