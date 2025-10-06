class Solution {
public:
    typedef tuple<int,int,int> T;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<T,vector<T>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;
        while(!pq.empty())
        {
            auto [time,row,col] = pq.top();
            pq.pop();
            if(row == n-1 && col == n-1) 
                return time;
            for(int i=0;i<4;i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    pq.push({max(time,grid[nrow][ncol]),nrow,ncol});
                }

            }
        }
        return -1;
    }
};