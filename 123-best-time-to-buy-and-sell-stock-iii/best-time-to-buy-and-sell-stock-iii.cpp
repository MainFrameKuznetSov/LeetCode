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
        //vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        vector<vector<int>>dp(n,vector<int>(k*2+1,0));
        vector<int>prev(k*2+1,0);
        for(int i=0;i<k*2;++i)
        {
            if(i%2!=0)
                prev[i]=prices[n-1];
        }
        for(int i=n-2;i>=0;--i)
        {
            vector<int>curr(k*2+1,0);
            for(int j=k*2-1;j>=0;--j)
            {
                int Buy=0,notBuy=0;
                if(j%2==0)//Buy
                {
                    int notTake=prev[j];
                    int Take=-prices[i]+prev[j+1];
                    Buy=max(notTake,Take);
                }
                else
                {
                    int notTake=prev[j];
                    int Take=prices[i]+prev[j+1];
                    notBuy=max(notTake,Take);
                }
                curr[j]=max(Buy,notBuy);
            }
            prev=curr;
        }
        return prev[0];
    }
};