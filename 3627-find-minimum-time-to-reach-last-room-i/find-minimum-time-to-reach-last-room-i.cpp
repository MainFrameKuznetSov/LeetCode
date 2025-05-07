class Solution {
public:
    int minTimeToReach(vector<vector<int>>&grid) {
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        vector<vector<int>>temp(n,vector<int>(m,INT_MAX));
        temp[0][0]=0;
        while(!pq.empty())
            {
                auto it=pq.top();
                pq.pop();
                int curr=it.first;
                int x=it.second.first,y=it.second.second;
                if(x==n-1 && y==m-1)
                    return curr;
                for(int i=0;i<4;++i)
                    {
                        int nx=x+dir[i].first;
                        int ny=y+dir[i].second;
                        if(nx>=0 && nx<n && ny>=0 && ny<m)
                        {
                            int wait=max(curr,grid[nx][ny])+1;
                            if(wait<temp[nx][ny])
                            {
                                temp[nx][ny]=wait;
                                pq.push({wait,{nx,ny}});
                            }
                        }
                    }
            }
    return -1;
    }
};