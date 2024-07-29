class Solution {
private:
    void dfs(int src,int dest,vector<int> adj[],vector<vector<int>> &dis,int d) 
    {
        dis[src][dest]=d;
        dis[dest][src]=d;
        for(auto iter:adj[src]) 
        {
            if(dis[iter][dest]-1>=d)
                dfs(iter,dest,adj,dis,d+1);
        }
    }

public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>adj[n+1];
        for(int i=1;i<n;++i) 
        {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
        vector<vector<int>>dis(n+1,vector<int>(n+1,INT_MAX));
        for(int i=1;i<=n;++i)
            dfs(i,i,adj,dis,0);
        vector<int>ans(n,0);
        for(int i=1;i<=n;++i) 
        {
            for(int j=1;j<=n;++j) 
            {
                if(dis[i][j]==0)
                    continue;
                ++ans[dis[i][j]-1];
            }
        }
        return ans;
    }
};