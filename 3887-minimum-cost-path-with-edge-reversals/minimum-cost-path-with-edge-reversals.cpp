#define INF (int)1e9

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:edges)
        {
            graph[it[1]].push_back({it[0],2*it[2]});
            graph[it[0]].push_back({it[1],it[2]});
        }
        set<pair<int,int>>st;
        st.insert({0,0});
        vector<int>dist(n,INF);
        dist[0]=0;
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            int node=top.second;
            for(auto it:graph[node])
            {
                int nxt=it.first,wt=it.second;
                if(dist[node]+wt<dist[nxt])
                {
                    dist[nxt]=dist[node]+wt;
                    st.insert({dist[nxt],nxt});
                }
            }
        }
        return dist[n-1]==INF?-1:dist[n-1];
    }
};