class Solution {
public:

    int f(int ind,int W,vector<int>&v,vector<vector<int>>&dp)
    {
        if(W==0)
            return 0;
        if(ind==0)
        {
            if(W%v[ind]==0)
                return W/v[ind];
            return 1e9;
        }

        if(dp[ind][W]!=-1)
            return dp[ind][W];

        int notTake=f(ind-1,W,v,dp),Take=INT_MAX;
        if(W>=v[ind])
            Take=1+f(ind,W-v[ind],v,dp);
        return dp[ind][W]=min(notTake,Take);

    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans=f(n-1,amount,coins,dp);
        // return ans==1e9?-1:ans;
        for(int i=1;i<=amount;++i)
            dp[0][i]=(i%coins[0]==0)?i/coins[0]:1e9;
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=amount;++j)
            {
                int notTake=dp[i-1][j],Take=INT_MAX;
                if(j>=coins[i])
                    Take=1+dp[i][j-coins[i]];
                dp[i][j]=min(notTake,Take);
            }
        }
        if(dp[n-1][amount]==1e9)
            return -1;
        return dp[n-1][amount];
    }
};