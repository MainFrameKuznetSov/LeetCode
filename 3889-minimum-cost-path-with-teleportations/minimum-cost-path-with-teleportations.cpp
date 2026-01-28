

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),hi=0;
        for(auto &it:grid)
        {
            for(int i:it)
                hi=max(hi,i);
        }
        vector<int>dp;
        vector<vector<int>>costs(m,vector<int>(n,INT_MAX));
        for(int x=0;x<=k;++x) 
        {
            for(int i=m-1;i>=0;--i) 
            {
                for(int j=n-1;j>=0;--j) 
                {
                    if(i+1==m && j+1==n)
                        costs[i][j]=0;
                    else 
                    {
                        costs[i][j]=INT_MAX;
                        if(i+1<m)
                            costs[i][j]=min(costs[i][j],costs[i+1][j]+grid[i+1][j]);
                        if(j+1<n)
                            costs[i][j]=min(costs[i][j],costs[i][j+1]+grid[i][j+1]);
                        if(x>0 && dp[grid[i][j]]<costs[i][j])
                            costs[i][j]=dp[grid[i][j]];
                    }
                }
            }
            dp.assign(hi+1,INT_MAX);
            for(int i=0;i<m;++i) 
            {
                for(int j=0;j<n;++j)
                    dp[grid[i][j]]=min(dp[grid[i][j]],costs[i][j]);
            }
            for(int i=1;i<=hi;++i)
                dp[i]=min(dp[i],dp[i-1]);
        }
        return costs[0][0];
    }
};

