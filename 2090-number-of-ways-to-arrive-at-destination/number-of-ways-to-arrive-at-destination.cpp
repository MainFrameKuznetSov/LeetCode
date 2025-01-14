class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<vector<int>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0LL;
        vector<int>ways(n,0);
        ways[0]=1;
        set<pair<long long,int>>st;
        st.insert({0LL,0});
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            long long dis=top.first;
            int node=top.second;
            //++ways[node];
            for(auto it:adj[node])
            {
                int nextNode=it[0],wt=it[1];
                if(dis+wt<dist[nextNode])
                {
                    ways[nextNode]=ways[node];
                    dist[nextNode]=dis+wt;
                    st.insert({dist[nextNode],nextNode});
                }
                else if(dis+wt==dist[nextNode])
                    ways[nextNode]=(ways[nextNode]+ways[node])%MOD;
            }
        }
        return ways[n-1]%MOD;
    }
};