#define pii pair<int,int>

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pii>>adj;
        for(vector<int>it:meetings) 
        {
            int u=it[0],v=it[1],time=it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        
        vector<bool>vis(n,0);
        while(!pq.empty()) 
        {
            auto [time,node]=pq.top();
            pq.pop();
            
            if(vis[node])
                continue;
            vis[node]=1;
            
            for(auto it:adj[node]) 
            {
                int nxt=it.first,t=it.second;
                
                if(t>=time && !vis[nxt])
                    pq.push({t,nxt});
            }
        }
        
        vector<int>ans;
        for(int i=0;i<n;++i) 
        {
            if(vis[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};