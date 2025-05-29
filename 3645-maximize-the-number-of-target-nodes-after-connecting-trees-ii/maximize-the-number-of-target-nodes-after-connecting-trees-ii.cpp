class Solution {
public:

    int dfs(int node,int prnt,vector<vector<int>>&adjL,vector<bool>&par,bool flag=1)
    {
        int ans=flag;
        par[node]=flag;
        for(int it:adjL[node])
        {
            if(it!=prnt)
                ans+=dfs(it,node,adjL,par,!flag);
        }
        return ans;
    }

    vector<vector<int>> build(vector<vector<int>>&edge)
    {
        vector<vector<int>>adjL(edge.size()+1);
        for(auto it:edge)
        {
            adjL[it[0]].push_back(it[1]);
            adjL[it[1]].push_back(it[0]);
        }
        return adjL;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m=edges1.size()+1,n=edges2.size()+1;
        vector<bool>par(m),vis(n);
        vector<vector<int>>adj1=build(edges1),adj2=build(edges2);
        int e1=dfs(0,-1,adj1,par),o1=m-e1,e2=dfs(0,-1,adj2,vis),o2=n-e2;
        vector<int>ans(m);
        for(int i=0;i<m;++i)
            ans[i]=max(e2,o2)+(par[i]?e1:o1);
        return ans;
    }
};