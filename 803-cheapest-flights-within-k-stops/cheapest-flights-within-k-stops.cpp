class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,src}});
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            int stops=top.first,price=top.second.first,node=top.second.second;
            for(auto it:adj[node])
            {
                int nextNode=it.first,cost=it.second;
                if(price+cost<dist[nextNode] && stops<=k)
                {
                    dist[nextNode]=price+cost;
                    st.insert({stops+1,{dist[nextNode],nextNode}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};