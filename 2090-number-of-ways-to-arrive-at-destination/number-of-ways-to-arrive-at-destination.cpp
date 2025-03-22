class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        dist[0]=0LL;
        set<pair<long long,int>>st;
        st.insert({0LL,0});
        while(!st.empty())
        {
            auto curr=*st.begin();
            st.erase(curr);
            long long dis=curr.first;
            int node=curr.second;
            for(auto it:adj[node])
            {
                //ways[it]=(ways[it]+ways[node])%MOD;
                int nextNode=it.first,wt=it.second;
                if(dis+wt<dist[nextNode])
                {
                    ways[nextNode]=ways[node];//Since this is the first time we reach the most optimum path, we have to re-initialise the ways to reach nextNode
                    dist[nextNode]=(long long)(dis+wt);
                    st.insert({dist[nextNode],nextNode});
                }
                else if(dis+wt==dist[nextNode])
                {
                    //cout<<node<<"---"<<dist[nextNode]<<"-->"<<nextNode<<"\n";
                    ways[nextNode]=(ways[nextNode]+ways[node])%MOD;
                    //st.insert({dist[nextNode],nextNode});
                }
            }
        }
        return ways[n-1]%MOD;
    }
};