#define MOD (int)(1e9+7)
#define ll long long

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<pair<ll,ll>>>dp(zero+1,vector<pair<ll,ll>>(one+1,{0,0}));
        for(int i=1;i<=min(zero,limit);++i)
            dp[i][0].first=1LL;
        for(int i=1;i<=min(one,limit);++i)
            dp[0][i].second=1LL;
        for(int i=1;i<=zero;i++)
        {
            for(int j=1;j<=one;j++)
            {
                ll moreZero=(i-limit>=1)?dp[i-limit-1][j].second:0;
                ll moreOne=(j-limit>=1)?dp[i][j-limit-1].first:0;
                dp[i][j].first=(dp[i-1][j].first+dp[i-1][j].second-moreZero+MOD)%MOD;
                dp[i][j].second=(dp[i][j-1].first+dp[i][j-1].second-moreOne+MOD)%MOD;
            }
        }
        return (dp[zero][one].first+dp[zero][one].second)%MOD;
        
    }
};