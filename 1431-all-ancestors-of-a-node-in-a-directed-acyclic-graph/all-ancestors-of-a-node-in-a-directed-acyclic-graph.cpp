class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n),graph(n);
        for(auto iter:edges)
            graph[iter[0]].push_back(iter[1]);
        for(int i=0;i<n;++i)
        {
            vector<bool>visit(n,false);
            dfs(graph,i,i,ans,visit);
        }
        for(int i=0;i<n;++i)
            sort(ans[i].begin(),ans[i].end());
        return ans;
    }
private:
    void dfs(vector<vector<int>>&graph,int prnt,int curr,vector<vector<int>>&ans,vector<bool>&visit)
    {
        visit[curr]=1;
        for(int iter:graph[curr])
        {
            if(!visit[iter])
            {
                ans[iter].push_back(prnt);
                dfs(graph,prnt,iter,ans,visit);
            }
        }
    }
};