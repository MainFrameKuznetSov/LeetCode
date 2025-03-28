class Solution {
public:

    vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size(),m=grid[0].size(),k=queries.size();
        vector<int>ans(k);
        vector<pair<int,int>>pr(k);
        for(int i=0;i<k;++i)
            pr[i]={queries[i],i};
        sort(pr.begin(),pr.end());
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        set<pair<int,pair<int,int>>>st;
        st.insert({grid[0][0],{0,0}});
        vis[0][0]=1;
        int res=0;
        for(int i=0;i<k;++i)
        {
            while(!st.empty() && (*st.begin()).first<pr[i].first)
            {
                ++res;
                auto top=*st.begin();
                st.erase(top);
                int r=top.second.first,c=top.second.second;
                for(int j=0;j<4;++j)
                {
                    int nr=r+dir[j].first,nc=c+dir[j].second;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        st.insert({grid[nr][nc],{nr,nc}});
                    }
                }
            }
            ans[pr[i].second]=res;
        }
        return ans;
    }
};