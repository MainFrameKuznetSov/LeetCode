class Solution {
public:
    int res;
    vector<long long>dp;
    void dfs(int node,int src,vector<vector<int>>&adj,vector<int>&val,int k)
    {
        dp[node]=val[node];
        for(int it:adj[node])
        {
            if(it!=src)
            {
                dfs(it,node,adj,val,k);
                dp[node]+=dp[it];
            }
        }
        if(dp[node]%k==0)
        {
            ++res;
            dp[node]=0;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& val, int k) {
        vector<vector<int>>adj(n);
        dp.resize(n,0LL);
        for(auto it:edges)
        {
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        res=0;
        dfs(0,-1,adj,val,k);
        return res;
    }
};