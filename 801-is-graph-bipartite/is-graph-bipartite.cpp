class Solution {
public:

    bool dfs(int node,vector<bool>&vis,vector<int>&color,vector<vector<int>>&adj,int col)
    {
        vis[node]=true;
        color[node]=col;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(!dfs(it,vis,color,adj,1-col))
                    return false;
            }
            else
            {
                if(color[it]==color[node])
                    return false;
                //return true;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;++i)
        {
            for(auto it:graph[i])
                adj[i].push_back(it);
        }
        vector<int>color(n,0);
        vector<bool>vis(n,false);
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                if(!dfs(i,vis,color,adj,color[i]))
                    return false;
            }
        }
        return true;
    }
};