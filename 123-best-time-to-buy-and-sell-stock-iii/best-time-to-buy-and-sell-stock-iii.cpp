class Solution {
public:

    int f(int ind,int buy,int count,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(ind==prices.size()-1)
        {
            if(buy)
                return 0;
            return prices[ind];
        }

        if(count>1)
            return 0;

        if(dp[ind][buy][count]!=-1)
            return dp[ind][buy][count];

        int Buy=0,notBuy=0;
        if(buy)
        {
            int notTake=f(ind+1,buy,count,prices,dp);
            int Take=-prices[ind]+f(ind+1,1-buy,count,prices,dp);
            Buy=max(Take,notTake);
        }
        else
        {
            int notTake=f(ind+1,buy,count,prices,dp);
            int Take=prices[ind]+f(ind+1,1-buy,count+1,prices,dp);
            notBuy=max(Take,notTake);
        }

        return dp[ind][buy][count]=max(Buy,notBuy);

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,1,0,prices,dp);
    }
};