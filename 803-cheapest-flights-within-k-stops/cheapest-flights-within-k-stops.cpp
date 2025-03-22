class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,src}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!st.empty())
        {
            auto curr=*st.begin();
            st.erase(curr);
            int stops=curr.first;
            int node=curr.second.second,cost=curr.second.first;
            for(auto it:adj[node])
            {
                int nextNode=it.first,price=it.second;
                if(cost+price<dist[nextNode] && stops<=k)
                {
                    dist[nextNode]=cost+price;
                    st.insert({stops+1,{dist[nextNode],nextNode}});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};