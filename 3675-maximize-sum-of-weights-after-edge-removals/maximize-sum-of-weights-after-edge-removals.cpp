class Solution {
    void dfs(vector<vector<pair<int,int>>>&adj,int u,int prnt,int k,vector<vector<long long>>&dp) 
    {
        vector<long long>differences;
        long long sumW=0;
        for (auto it:adj[u]) 
        {
            if(it.first==prnt) 
                continue;

            dfs(adj,it.first,u,k,dp);

            differences.push_back(it.second+dp[it.first][1]-dp[it.first][0]);

            sumW+=dp[it.first][0];
        }

        sort(rbegin(differences),rend(differences));

        dp[u][0]=sumW;
        for (int i=0;i<min(k,(int)differences.size());++i) 
        {
            if (differences[i]>0) 
                dp[u][0]+=differences[i];
        }

        dp[u][1]=sumW;
        for(int i=0;i<min(k-1,(int)differences.size());++i) 
        {
            if(differences[i]>0) 
                dp[u][1]+=differences[i];
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