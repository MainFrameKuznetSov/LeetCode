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
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        vector<int>prev(2,0),curr1(2,0);
        //return f(0,1,prices,dp);
        for(int ind=n-1;ind>=0;--ind)
        {
            vector<int>curr2(2,0);
            for(int canBuy=0;canBuy<=1;++canBuy)
            {
                int Buy=0,notBuy=0;
                if(canBuy)
                {
                    int notTake=curr1[canBuy];
                    int Take=-prices[ind]+curr1[1-canBuy];
                    Buy=max(notTake,Take);
                }
                else
                {
                    int notTake=curr1[canBuy];
                    int Take=prices[ind]+prev[1-canBuy];
                    notBuy=max(notTake,Take);
                }
                curr2[canBuy]=max(Buy,notBuy);
            }
            prev=curr1;
            curr1=curr2;
        }
        return curr1[1];
    }
};