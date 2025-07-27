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
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(1,n-2,cuts,dp);
    }
};