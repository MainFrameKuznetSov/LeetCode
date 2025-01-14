class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        dist[src]=0;
        vector<vector<int>>adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,src}});
        while(!st.empty())
        {
            auto top=*st.begin();
            int stops=top.first;
            int node=top.second.second;
            int cost=top.second.first;
            st.erase(top);
            if(stops>k)
                continue;
            for(auto it:adj[node])
            {
                int nextNode=it[0],price=it[1];
                //cout<<node<<" "<<cost<<" "<<nextNode<<" "<<price<<"\n";
                if(cost+price<dist[nextNode] && stops<=k)
                {
                    dist[nextNode]=cost+price;
                    st.insert({stops+1,{dist[nextNode],nextNode}});
                    //cout<<"Change "<<dist[nextNode]<<" "<<nextNode<<" "<<stops+1<<"\n";
                }
            }
        }
        // for(int i=0;i<n;++i)
        //     cout<<dist[i]<<" ";
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};