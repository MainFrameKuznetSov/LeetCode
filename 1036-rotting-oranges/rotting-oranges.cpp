class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else
                    vis[i][j]=0;
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int r=q.front().first.first,c=q.front().first.second,t=q.front().second;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;++i)
            {
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                {
                    q.push({{nr,nc},t+1});
                    ans=max(ans,t+1);
                    grid[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!vis[i][j] && grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};