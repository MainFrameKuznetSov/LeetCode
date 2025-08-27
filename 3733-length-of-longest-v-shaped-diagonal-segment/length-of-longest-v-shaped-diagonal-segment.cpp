class Solution {
public:

    // int dfs(int i,int j,int valToFind,vector<vector<int>>&grid,
    // vector<vector<bool>>&vis)
    // {
    //     cout<<i<<" "<<j<<"\n";
    //     vis[i][j]=true;
    //     int target=(grid[i][j]==2)?0:2,n=grid.size(),m=grid[0].size();

    //     for(int k=0;k<4;++k)
    //     {
    //         int ni=i+dir[k].first,nj=j+dir[k].second;
    //         if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==target && !vis[ni][nj])
    //             return 1+dfs(ni,nj,target,grid,vis);
    //     }

    //     return 1; 
    // }

    int getNext(int direction)
    {
        if(direction==0)
            return 0;
        return direction==4?1:direction+1;
    }

    bool isValid(int i,int j,int n,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    int f(int i,int j,int direction,vector<vector<int>>&grid,int k,vector
    <vector<vector<int>>>&dp)
    {
        int n=grid.size(),m=grid[0].size();
        if(!isValid(i,j,n,m) || k>1)
            return 0;

        if(dp[i][j][direction*2+k]!=-1)
            return dp[i][j][direction*2+k];

        int target=(grid[i][j]==2)?0:2;
        
        // cout<<i<<" "<<j<<" "<<direction<<" "<<k<<"\n";

        // vector<pair<int,int>>dir={{-1,1},{1,1},{1,-1},{-1,-1}};
        int upRight=0,downRight=0,downLeft=0,upLeft=0;
        if(isValid(i-1,j+1,n,m) && grid[i-1][j+1]==target)
        {
            if(getNext(direction)==1 && k+1<2)
                upRight=1+f(i-1,j+1,1,grid,k+1,dp);
            else if(direction==0 || direction==1)
                upRight=1+f(i-1,j+1,1,grid,k,dp);
        }
        if(isValid(i+1,j+1,n,m) && grid[i+1][j+1]==target)
        {
            if(getNext(direction)==2 && k+1<2)
                downRight=1+f(i+1,j+1,2,grid,k+1,dp);
            else if(direction==0 || direction==2)
                downRight=1+f(i+1,j+1,2,grid,k,dp);
        }
        if(isValid(i+1,j-1,n,m) && grid[i+1][j-1]==target)
        {
            if(getNext(direction)==3 && k+1<2)
                downLeft=1+f(i+1,j-1,3,grid,k+1,dp);
            else if(direction==0 || direction==3)
                downLeft=1+f(i+1,j-1,3,grid,k,dp);
        }
        if(isValid(i-1,j-1,n,m) && grid[i-1][j-1]==target)
        {
            if(getNext(direction)==4 && k+1<2)
                upLeft=1+f(i-1,j-1,4,grid,k+1,dp);
            else if(direction==0 || direction==4)
                upLeft=1+f(i-1,j-1,4,grid,k,dp);
        }

        return dp[i][j][direction*2+k]=max({upRight,downRight,downLeft,upLeft});
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,
        vector<vector<int>>(m,
        vector<int>(10,-1)));
        int ans=0;   
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                    ans=max(ans,1+f(i,j,0,grid,0,dp));
            }
        }         
        return ans;
    }
};