class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m)
    {
        vis[i][j]=1;
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int k=0;k<4;++k)
        {
            int ni=i+di[k],nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]=='1')
                dfs(ni,nj,vis,grid,n,m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ++ans;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return ans;
    }
};