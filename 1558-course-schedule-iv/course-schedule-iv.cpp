class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(auto i:prerequisites)
            adj[i[0]].push_back(i[1]);
        vector<int>indeg(n,0),topo;
        for(int i=0;i<n;++i)
        {
            for(auto it:adj[i])
                ++indeg[it];
        }
        queue<int>q;
        for(int i=0;i<n;++i)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        unordered_map<int,set<int>>mp;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                mp[it].insert(node);
                for(auto t:mp[node])
                    mp[it].insert(t);
                --indeg[it];
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();++i)
        {
            if(mp[queries[i][1]].contains(queries[i][0]))
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};