class Solution {
public:

    bool dfs(int node,vector<bool>&vis,vector<int>&color,int col,vector<vector<int>>&graph)
    {
        vis[node]=1;
        color[node]=col;
        for(int it:graph[node])
        {
            if(!vis[it])
            {
                if(!dfs(it,vis,color,1-color[node],graph))
                    return 0;
            }
            else
            {
                if(color[node]==color[it])
                    return 0;
            }
        }
        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        vector<bool>vis(n,0);
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                if(!dfs(i,vis,color,color[i],graph))
                    return 0;
            }
        }
        return 1;
    }
};