class Solution {
public:
    int orangesRotting(vector<vector<int>>&grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        queue<pair<int,pair<int,int>>>q;//{time,{row,col}}
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        int ans=0;

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int time=node.first,row=node.second.first,col=node.second.second;
            ans=time;
            for(int k=0;k<4;++k)
            {
                int nrow=row+dir[k].first,ncol=col+dir[k].second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && 
                   grid[nrow][ncol]==1)
                {
                    q.push({time+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                }
            }
        }

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};