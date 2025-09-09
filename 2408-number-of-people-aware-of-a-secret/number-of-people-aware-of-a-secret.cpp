#define MOD 1000000007

class Solution {
public:

    int f(int n,int delay,int forget,vector<int>&dp)
    {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;

        if(dp[n]!=-1)
            return dp[n];
        
        int res=0;
        for(int i=n-forget+1;i<=n-delay;++i)
        {
            if(i>0)
                res=(res+f(i,delay,forget,dp))%MOD;
        }
        return dp[n]=res;
        
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,-1);
        int res=0;
        for(int i=n-forget+1;i<=n;++i)
        {
            if(i>0)
                res=(res+f(i,delay,forget,dp))%MOD;
        }
        return res;
    }
};