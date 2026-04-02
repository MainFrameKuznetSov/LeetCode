class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        dp[0][0][0]=coins[0][0];
        if(coins[0][0]<0) 
        {
            for(int i=1;i<3;++i)
                dp[0][0][i]=0;
        }
        for(int i=0;i<n;++i) 
        {
            for(int j=0;j<m;++j) 
            {
                for(int k=0;k<3;++k) 
                {
                    if(dp[i][j][k]!=INT_MIN) 
                    {
                        if(i<n-1) 
                        {
                            dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+coins[i+1][j]);
                            if(coins[i+1][j]<0)
                            {
                                if(k<2)
                                    dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]);
                            }
                        }
                        
                        if(j<m-1)
                        {
                            dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+coins[i][j+1]);
                            if(coins[i][j+1]<0)
                            {
                                if(k<2)
                                    dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]);
                            }
                        }
                    }
                }
            }
        }
        return max(dp[n-1][m-1][0],max(dp[n-1][m-1][1],dp[n-1][m-1][2]));
    }
};