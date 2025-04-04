class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges)
            adj[it[0]].push_back({it[1],it[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n=adj.size();
        vector<int>dist(n,INT_MAX);
        dist[node1]=0;
        set<pair<int,int>>st;
        st.insert({0,node1});
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            int dis=top.first,node=top.second;
            for(auto it:adj[node])
            {
                int nextNode=it.first,wt=it.second;
                if(dis+wt<dist[nextNode])
                {
                    dist[nextNode]=dis+wt;
                    st.insert({dis+wt,nextNode});
                }
            }
        }
        return(dist[node2]==INT_MAX)?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */