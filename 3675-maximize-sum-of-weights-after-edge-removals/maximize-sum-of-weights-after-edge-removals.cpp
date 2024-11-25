class Solution {
    void dfs(vector<vector<pair<int,int>>>&adj,int u,int prnt,int k,vector<vector<long long>>&dp) 
    {
        vector<long long>diff;
        long long sumW=0;
        for (auto it:adj[u]) 
        {
            if(it.first==prnt) 
                continue;

            dfs(adj,it.first,u,k,dp);

            diff.push_back(it.second+dp[it.first][1]-dp[it.first][0]);

            sumW+=dp[it.first][0];
        }

        sort(rbegin(diff),rend(diff));

        dp[u][0]=sumW;
        for(int i=0;i<min(k,(int)diff.size());++i) 
        {
            if(diff[i]>0) 
                dp[u][0]+=diff[i];
        }

        dp[u][1]=sumW;
        for(int i=0;i<min(k-1,(int)diff.size());++i) 
        {
            if(diff[i]>0) 
                dp[u][1]+=diff[i];
        }
    }

public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>>adj(n);

        for(auto it:edges) 
        {
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        dfs(adj,0,-1,k,dp);
        return dp[0][0];
    }
};