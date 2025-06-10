class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty())
        {
            int i=q.front().first.first,j=q.front().first.second,time=q.front().second;
            q.pop();
            ans=time;
            for(int k=0;k<4;++k)
            {
                int ni=i+dir[k].first,nj=j+dir[k].second;
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1 && !vis[ni][nj])
                {
                    vis[ni][nj]=1;
                    grid[ni][nj]=2;
                    q.push({{ni,nj},time+1});
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};