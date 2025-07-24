class Solution {
public:

    int f(int ind,int buy,int count,vector<int>&prices,vector<vector<vector<int>>>&dp,int k)
    {
        if(ind==prices.size()-1)
        {
            if(buy)
                return 0;
            return prices[ind];
        }

        if(count>k-1)
            return 0;

        if(dp[ind][buy][count]!=-1)
            return dp[ind][buy][count];

        int Buy=0,notBuy=0;
        if(buy)
        {
            int notTake=f(ind+1,buy,count,prices,dp,k);
            int Take=-prices[ind]+f(ind+1,1-buy,count,prices,dp,k);
            Buy=max(Take,notTake);
        }
        else
        {
            int notTake=f(ind+1,buy,count,prices,dp,k);
            int Take=prices[ind]+f(ind+1,1-buy,count+1,prices,dp,k);
            notBuy=max(Take,notTake);
        }

        return dp[ind][buy][count]=max(Buy,notBuy);

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),k=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return f(0,1,0,prices,dp,k);
    }
};