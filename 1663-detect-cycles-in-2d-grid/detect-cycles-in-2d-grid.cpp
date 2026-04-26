class Solution {
public:

    vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};

    bool dfs(int i,int j,int pi,int pj,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m)
    {
        vis[i][j]=1;
        for(int k=0;k<4;++k)
        {
            int ni=i+dir[k].first,nj=j+dir[k].second;
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==grid[i][j])
            {
                if(!vis[ni][nj])
                {
                    if(dfs(ni,nj,i,j,vis,grid,n,m))
                        return true;
                }
                else if(!(ni==pi && nj==pj))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!vis[i][j])
                {
                    if(dfs(i,j,-1,-1,vis,grid,n,m))
                        return true;
                }
            }
        }
        return false;
    }
};