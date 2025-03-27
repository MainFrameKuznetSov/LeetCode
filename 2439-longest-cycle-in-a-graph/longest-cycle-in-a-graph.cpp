class Solution {
public:

    int ans;

    void dfs(int node,vector<bool>&vis,vector<bool>&pathVis,vector<int>&cnt,vector<int>&edges)
    {
        vis[node]=1;
        pathVis[node]=1;
        int it=edges[node];
        if(it!=-1 && !vis[it])
        {
            cnt[it]=cnt[node]+1;
            dfs(it,vis,pathVis,cnt,edges);
        }
        else if(it!=-1 && vis[it] && pathVis[it])//Cycle
            ans=max(ans,cnt[node]-cnt[it]+1);

        pathVis[node]=0;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool>vis(n,0),pathVis(n,0);
        vector<int>cnt(n,1);
        ans=-1;
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
                dfs(i,vis,pathVis,cnt,edges);
        }
        return ans;
    }
};