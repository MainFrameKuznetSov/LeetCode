class Solution {
public:
    static int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for (int i=0;i<n;++i)
            dp[i][m-1]=1;
        for(int j=m-2;j>=0;--j) 
        {
            for(int i=0;i<n;++i) 
            {
                int x=grid[i][j];
                int temp=(x<grid[i][j+1])*dp[i][j+1];
                if(i>0 && x<grid[i-1][j+1])
                    temp=max(temp,dp[i-1][j+1]);
                if(i<n-1 && x<grid[i+1][j+1])
                    temp=max(temp,dp[i+1][j+1]);
                dp[i][j]=1+temp;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
            ans=max(ans,dp[i][0]);
        return ans-1;
    }
};