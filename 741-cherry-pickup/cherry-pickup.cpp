class Solution {
public:
    int f(int i1,int j1,int i2,int n,vector<vector<int>>&grid,
    vector<vector<vector<int>>>&dp)
    {
        int j2=i1+j1-i2;
        if(i1>=n || i2>=n || j1>=n || j2>=n || j2<0 || grid[i1][j1]==-1 || grid[i2][j2]==-1)
            return INT_MIN;
        if(i1==n-1 && j1==n-1)
            return grid[i1][j1];
        
        if(dp[i1][j1][i2]!=-1)
            return dp[i1][j1][i2];

        int totalPickup=grid[i1][j1];
        if(i1!=i2 || j1!=j2)
            totalPickup+=grid[i2][j2];

        int bestChoice=max(
                            max(f(i1+1,j1,i2+1,n,grid,dp),
                            f(i1+1,j1,i2,n,grid,dp)),
                            max(f(i1,j1+1,i2+1,n,grid,dp),
                            f(i1,j1+1,i2,n,grid,dp))
                        );
                    
        // if(bestChoice==INT_MIN)
        //     return dp[i1][j1][i2]=INT_MIN;

        return dp[i1][j1][i2]=totalPickup+bestChoice;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,f(0,0,0,n,grid,dp));
    }
};