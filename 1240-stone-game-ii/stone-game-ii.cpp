class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>psum(n+1,0);
        for(int i=n-1;i>=0;--i)
            psum[i]=psum[i+1]+piles[i];
        for(int i=n-1;i>=0;--i)
        {
            for(int j=1;j<=n;++j)
            {
                if(n<=j*2+i)
                    dp[i][j]=psum[i];
                else
                {
                    for(int k=1;k<=j*2;++k)
                        dp[i][j]=max(dp[i][j],psum[i]-dp[i+k][max(j,k)]);
                }
            }
        }
        return dp[0][1];
    }
};