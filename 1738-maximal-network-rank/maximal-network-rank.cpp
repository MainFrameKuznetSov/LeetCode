class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indeg(n,0);
        set<pair<int,int>>st;
        for(auto it:roads)
        {
            ++indeg[it[0]];
            ++indeg[it[1]];
            st.insert({it[0],it[1]});
            st.insert({it[1],it[0]});
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int temp=indeg[i]+indeg[j];
                if(st.count({i,j}))
                    --temp;
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};