class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>>dq;

        dist[0][0]=0;
        dq.push_front({0,0});
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};

        while(!dq.empty()) 
        {
            auto [x,y]=dq.front();
            dq.pop_front();
            for (auto [dx,dy]:dir)
            {
                int nx=x+dx,ny=y+dy;
                if (nx>=0 && nx<m && ny>=0 && ny<n) 
                {
                    int d=dist[x][y]+grid[nx][ny];
                    if(d<dist[nx][ny]) 
                    {
                        dist[nx][ny]=d;
                        if(grid[nx][ny]==0)
                            dq.push_front({nx,ny});
                        else
                            dq.push_back({nx,ny});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};