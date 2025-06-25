class Solution {

private:
    int ans;
public:

    void dfs(int node,int time,int tLimit,int sum,vector<int>&memo,vector<vector<pair<int,int>>>&adj)
    {
        if(time>tLimit)
            return ;
        sum+=memo[node];// Sum 
        if(node==0)
            ans=max(ans,sum);
        int prev=memo[node];
        memo[node]=0;
        for(auto it:adj[node])
            dfs(it.first,time+it.second,tLimit,sum,memo,adj);
        memo[node]=prev;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        ans=0;
        dfs(0,0,maxTime,0,values,adj);
        return ans;
    }
};