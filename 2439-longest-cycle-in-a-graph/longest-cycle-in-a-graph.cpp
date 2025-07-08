class Solution {
public:

    int ans;

    void dfs(int node,vector<int>&edges,vector<int>&cnt,vector<int>&vis)
    {
        vis[node]=2;
        if(edges[node]!=-1)
        {
            if(vis[edges[node]]==2)
                ans=max(ans,cnt[node]-cnt[edges[node]]+1);
            else if(vis[edges[node]]==0)
            {
                cnt[edges[node]]=cnt[node]+1;
                dfs(edges[node],edges,cnt,vis);
            }
        }
        vis[node]=1;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        ans=-1;
        vector<int>cnt(n,0),vis(n,0);
        for(int i=0;i<n;++i)
        {
            if(vis[i]==0)
                dfs(i,edges,cnt,vis);
        }
        return ans;
    }
};