class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n],indeg(n,0),topo;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<graph[i].size();++j)
                adj[graph[i][j]].emplace_back(i);
        }
        for(int i=0;i<n;++i)
        {
            for(auto iter:adj[i])
                ++indeg[iter];
        }
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            topo.emplace_back(node);
            q.pop();
            for(auto iter:adj[node])
            {
                --indeg[iter];
                if(indeg[iter]==0)
                    q.push(iter);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};