class Solution {
public:

    int f(int i,int buy,int count,vector<int>&prices,vector<vector<vector<int>>>&dp,int k)
    {
        if(i==prices.size()-1)
        {
            if(buy)
                return 0;
            return prices[i];
        }

        if(count>k-1)
            return 0;

        if(dp[i][buy][count]!=-1)
            return dp[i][buy][count];

        int Buy=0,notBuy=0;
        if(buy)
        {
            int notTake=f(i+1,buy,count,prices,dp,k);
            int Take=-prices[i]+f(i+1,1-buy,count,prices,dp,k);
            Buy=max(Take,notTake);
        }
        else
        {
            int notTake=f(i+1,buy,count,prices,dp,k);
            int Take=prices[i]+f(i+1,1-buy,count+1,prices,dp,k);
            notBuy=max(Take,notTake);
        }

        return dp[i][buy][count]=max(Buy,notBuy);

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size(),k=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        vector<vector<int>>prev(2,vector<int>(k+1,0));
        //return f(0,1,0,prices,dp,k);
        for(int buy=0;buy<=1;++buy)
        {
            for(int count=0;count<k;++count)
                prev[buy][count]=buy?0:prices[n-1];
        }

        for(int i=n-2;i>=0;--i)
        {
            vector<vector<int>>curr(2,vector<int>(k+1,0));
            for(int buy=0;buy<=1;++buy)
            {
                for(int count=0;count<k;++count)
                {
                    int Buy=0,notBuy=0;
                    if(buy)
                    {
                        int notTake=prev[buy][count];
                        int Take=-prices[i]+prev[1-buy][count];
                        Buy=max(Take,notTake);
                    }
                    else
                    {
                        int notTake=prev[buy][count],Take=0;
                        Take=prices[i]+prev[1-buy][count+1];
                        notBuy=max(Take,notTake);
                    }

                    curr[buy][count]=max(Buy,notBuy);
                }
            }
            prev=curr;
        }

        return prev[1][0];

    }
};