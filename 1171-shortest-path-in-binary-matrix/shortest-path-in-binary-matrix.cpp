class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int n=grid.size();
        vector<int>dist(n*n,1e9);
        dist[0]=0;
        set<pair<int,int>>st;
        st.insert({0,0});
        while(!st.empty())
        {
            auto top=*st.begin();
            int dis=top.first,node=top.second;
            st.erase(top);
            int r=node/n,c=node%n;
            for(int i=-1;i<=1;++i)
            {
                for(int j=-1;j<=1;++j)
                {
                    int ni=i+r,nj=j+c;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0)
                    {
                        if(dis+1<dist[ni*n+nj])
                        {
                            dist[ni*n+nj]=dis+1;
                            st.insert({dis+1,ni*n+nj});
                        }
                    }
                }
            }
        }
        if(dist[n*n-1]==1e9)
            return -1;
        return dist[n*n-1]+1;
    }
};