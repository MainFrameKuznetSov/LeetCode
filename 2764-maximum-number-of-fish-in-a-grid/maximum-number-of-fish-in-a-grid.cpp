class Solution {
public:

    int bfs(int r,int c,vector<vector<int>>&grid)
    {
        int ans=grid[r][c],n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]=0;
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;++i)
            {
                int nx=x+dir[i].first,ny=y+dir[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]>0)
                {
                    q.push({nx,ny});
                    ans+=grid[nx][ny];
                    grid[nx][ny]=0;
                }
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]>0)
                    ans=max(ans,bfs(i,j,grid));
            }
        }
        return ans;
    }
};