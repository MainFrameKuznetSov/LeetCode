class Solution {

private:
    int curr=1;

public:

    void dfs(int node,int prnt,vector<bool>&vis,vector<int>adj[],int tIn[],int low[],vector<vector<int>>&ans)
    {
        vis[node]=1;
        tIn[node]=low[node]=curr;
        ++curr;
        for(auto it:adj[node])
        {
            if(it==prnt)
                continue;
            if(vis[it])
                low[node]=min(low[it],low[node]);
            else
            {
                dfs(it,node,vis,adj,tIn,low,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>tIn[node])
                    ans.push_back({it,node});
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<bool>vis(n,0);
        int tIn[n],low[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans;
        dfs(0,-1,vis,adj,tIn,low,ans);
        return ans;
    }
};