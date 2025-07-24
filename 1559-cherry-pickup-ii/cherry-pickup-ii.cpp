#define MIN -1e9

class Solution {
public:

    // int f(int x,int y1,int y2,vector<vector<int>>&mat,vector<vector<vector<int>>>&dp,int n,int m)
    // {
    //     if(y1<0 || y2<0 ||  y1>=m || y2>=m)
    //         return MIN;

    //     if(dp[x][y1][y2]!=-1)
    //         return dp[x][y1][y2];

    //     if(x==n-1)
    //     {
    //         if(y1==y2)
    //             return mat[x][y1];
    //         else
    //             return mat[x][y1]+mat[x][y2];
    //     }

        

    //     return dp[x][y1][y2]=mx;
        
    // }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>prev(m,vector<int>(m,0));
        //return f(0,0,m-1,grid,dp,n,m);
        for(int y1=0;y1<m;++y1)
        {
            for(int y2=0;y2<m;++y2)
            {
                if(y1==y2)
                    prev[y1][y2]=grid[n-1][y1];
                else
                    prev[y1][y2]=grid[n-1][y1]+grid[n-1][y2];
            }
        }

        for(int x=n-2;x>=0;--x)
        {
            vector<vector<int>>curr(m,vector<int>(m,0));
            for(int y1=0;y1<m;++y1)
            {
                for(int y2=0;y2<m;++y2)
                {
                    int mx=MIN;
                    for(int i=-1;i<=1;++i)
                    {
                        for(int j=-1;j<=1;++j)
                        {
                            if(y1+i>=0 && y1+i<m && y2+j>=0 && y2+j<m)
                            {
                                if(y1==y2)
                                    mx=max(mx,grid[x][y1]+prev[y1+i][y2+j]);
                                else
                                    mx=max(mx,grid[x][y1]+grid[x][y2]+prev[y1+i][y2+j]);
                            }
                        }
                    }
                    curr[y1][y2]=mx;
                }
            }
            prev=curr;
        }
        return prev[0][m-1];
    }
};