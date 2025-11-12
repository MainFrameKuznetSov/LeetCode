#define INF (int)1e9
#define MOD (int)(1e9+7)
#define ll long long

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>dist(n,(ll)(5e16));
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        set<pair<ll,int>>pq;
        pq.insert({0,0});
        while(!pq.empty())
        {
            auto top=*pq.begin();
            pq.erase(top);
            ll dis=top.first;
            int node=top.second;
            for(auto it:adj[node])
            {
                int nxt=it.first,wt=it.second;
                if(dis+wt<dist[nxt])
                {
                    dist[nxt]=dis+wt;
                    ways[nxt]=ways[node];
                    pq.insert({dis+wt,nxt});
                }
                else if(dis+wt==dist[nxt])
                    ways[nxt]=(ways[nxt]+ways[node])%MOD;
            }
        }
        return ways[n-1];
    }
};