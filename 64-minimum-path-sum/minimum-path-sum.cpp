class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>dp(n,0);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int up=grid[i][j],left=grid[i][j];
                if(i==0 && j==0)
                    dp[j]=grid[i][j];
                else
                {
                    if(i>0)
                        up+=dp[j];
                    else
                        up=INT_MAX;
                    if(j>0)
                        left+=dp[j-1];
                    else
                        left=INT_MAX;
                    dp[j]=min(up,left);
                }
            }
        }
        return dp[n-1];
    }
};