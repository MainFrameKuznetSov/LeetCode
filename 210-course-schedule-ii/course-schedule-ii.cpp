class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>&pre) {
        vector<int>adj[n],indeg(n,0),topo;
        for(int i=0;i<pre.size();++i)
            adj[pre[i][1]].emplace_back(pre[i][0]);
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
        if(topo.size()==n)
            return topo;
        else
            return {};
    }
};