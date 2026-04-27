class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<int,int>>>dir={{{0,-1},{0,1}},
                                          {{-1,0},{1,0}},
                                          {{0,-1},{1,0}},
                                          {{0,1},{1,0}},
                                          {{0,-1},{-1,0}},
                                          {{0,1},{-1,0}}};
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty())
        {
            auto top=q.front();
            int r=top.first,c=top.second;
            q.pop();
            if(r==n-1 && c==m-1)
                return true;
            for(auto it:dir[grid[r][c]-1])
            {
                int nr=r+it.first,nc=c+it.second;
                if(nr<0 || nc<0 || nr>=n || nc>=m || vis[nr][nc])
                    continue;
                for(auto ti:dir[grid[nr][nc]-1])
                {
                    if(nr+ti.first==r && nc+ti.second==c)
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
};