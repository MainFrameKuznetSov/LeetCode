#define ll long long
#define INF (ll)-5e18

class Solution {
public:

    ll memo(int ind,vector<int>&prices,int k,int operation,vector<vector<vector<ll>>>&dp)
    {

        if(ind>=prices.size() || k==0)
        {
            if(operation==0)
                return 0;
            else//Say transaction is processed but not finished
                return INF;
        }

        if(dp[ind][k][operation]!=-1)
            return dp[ind][k][operation];
 
        ll notTake=memo(ind+1,prices,k,operation,dp),Take;
        if(operation==1)//sell
            Take=prices[ind]+memo(ind+1,prices,k-1,0,dp);
        else if(operation==2)//buy
            Take=-prices[ind]+memo(ind+1,prices,k-1,0,dp);
        else
            Take=max(-prices[ind]+memo(ind+1,prices,k,1,dp),prices[ind]+memo(ind+1,prices,k,2,dp));
        
        return dp[ind][k][operation]=max(notTake,Take);

    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(k+1,vector<ll>(3,-1)));
        return memo(0,prices,k,0,dp);
    }
};