class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<int>dist(n*m,1e9);
        dist[0]=0;
        set<pair<int,int>>st;
        st.insert({0,0});
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!st.empty())
        {
            auto top=*st.begin();
            int dis=top.first,node=top.second;
            st.erase({dis,node});
            int i=node/m,j=node%m;
            for(int k=0;k<4;++k)
            {
                int ni=i+dir[k].first,nj=j+dir[k].second;
                if(ni>=0 && ni<n && nj>=0 && nj<m)
                {
                    int newDist=max(dis,abs(heights[ni][nj]-heights[i][j]));
                    if(newDist<dist[ni*m+nj])
                    {
                        dist[ni*m+nj]=newDist;
                        st.insert({newDist,ni*m+nj});
                    }
                }
            }
        }
        return dist[n*m-1];
    }
};