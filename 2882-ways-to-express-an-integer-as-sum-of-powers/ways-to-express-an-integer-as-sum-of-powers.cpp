#define MOD 1000000007

class Solution {
public:

    int f(int ind,int W,vector<int>&v,vector<vector<int>>&dp)
    {
        //cout<<ind<<" "<<W<<"\n";

        if(W==0)
            return 1;

        if(ind==0)
        {
            if(W==v[0])
                return 1;
            return 0;
        }
        
        if(dp[ind][W]!=-1)
            return dp[ind][W];

        int notTake=f(ind-1,W,v,dp),Take=0;
        if(W>=v[ind])
            Take=f(ind-1,W-v[ind],v,dp);
        return dp[ind][W]=(Take+notTake)%MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int>v;
        for(int i=1;pow(i,x)<=n;++i)
            v.push_back(pow(i,x));
        // for(int i:v)
        //     cout<<i<<" ";
        // cout<<"\n";
        int sz=v.size();
        vector<vector<int>>dp(sz,vector<int>(n+1,-1));
        return f(sz-1,n,v,dp);
    }
};