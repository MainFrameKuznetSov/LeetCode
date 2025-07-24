#define MIN -1e9

class Solution {
public:

    int f(int x,int y1,int y2,vector<vector<int>>&mat,vector<vector<vector<int>>>&dp,int n,int m)
    {
        if(y1<0 || y2<0 ||  y1>=m || y2>=m)
            return MIN;

        if(dp[x][y1][y2]!=-1)
            return dp[x][y1][y2];

        if(x==n-1)
        {
            if(y1==y2)
                return mat[x][y1];
            else
                return mat[x][y1]+mat[x][y2];
        }

        int mx=MIN;
        for(int i=-1;i<=1;++i)
        {
            for(int j=-1;j<=1;++j)
            {
                if(y1==y2)
                    mx=max(mx,mat[x][y1]+f(x+1,y1+i,y2+j,mat,dp,n,m));
                else
                    mx=max(mx,mat[x][y1]+mat[x][y2]+f(x+1,y1+i,y2+j,mat,dp,n,m));
            }
        }

        return dp[x][y1][y2]=mx;
        
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp,n,m);
    }
};