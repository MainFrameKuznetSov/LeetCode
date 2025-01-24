class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>lim;
        for(int i=0;i<n;++i)
        {
            vector<int>l;
            for(int j=0;j<=i;++j)
                l.push_back(INT_MAX);
            lim.push_back(l);
        }
        set<pair<int,pair<int,int>>>st;
        lim[0][0]=triangle[0][0];
        st.insert({lim[0][0],{0,0}});
        vector<pair<int,int>>dir={{1,0},{1,1}};
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            int dis=top.first,r=top.second.first,c=top.second.second;
            for(int i=0;i<2;++i)
            {
                int nr=r+dir[i].first,nc=c+dir[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<triangle[nr].size())
                {
                    if(dis+triangle[nr][nc]<lim[nr][nc])
                    {
                        lim[nr][nc]=dis+triangle[nr][nc];
                        st.insert({lim[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;++i)
            ans=min(ans,lim[n-1][i]);
        return ans;
    }
};