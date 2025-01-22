class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>&grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<int>q;
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j])
                {
                    ans[i][j]=0;
                    q.push(i*m+j);
                }
            }
        }
        while(!q.empty())
        {
            int r=q.front()/m,c=q.front()%m;
            q.pop();
            for(int i=0;i<4;++i)
            {
                int nr=r+dir[i].first,nc=c+dir[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==-1)
                {
                    ans[nr][nc]=ans[r][c]+1;
                    q.push(nr*m+nc);
                }
            }
        }
        return ans;
    }
};