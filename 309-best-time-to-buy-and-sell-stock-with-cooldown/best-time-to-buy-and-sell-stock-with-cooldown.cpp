class Solution {
public:

    int f(int ind,int canBuy,vector<int>&prices,vector<vector<int>>&dp)
    {
        
        if(ind>=prices.size())
            return 0;
        
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];
        
        int Buy=0,notBuy=0;
        if(canBuy)
        {
            int notTake=f(ind+1,canBuy,prices,dp);
            int Take=-prices[ind]+f(ind+1,1-canBuy,prices,dp);
            Buy=max(notTake,Take);
        }
        else
        {
            int notTake=f(ind+1,canBuy,prices,dp);
            int Take=prices[ind]+f(ind+2,1-canBuy,prices,dp);
            notBuy=max(notTake,Take);
        }
        
        return dp[ind][canBuy]=max(Buy,notBuy);
        
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};