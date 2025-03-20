class Solution {
public:

    vector<int>prnt,depth;

    int findUPar(int node)
    {
        if(prnt[node]==-1)
            return node;
        return prnt[node]=findUPar(prnt[node]);
    }

    void UnionByDepth(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return ;
        if(depth[ulp_u]<depth[ulp_v])
            swap(ulp_u,ulp_v);
        prnt[ulp_v]=ulp_u;
        if(depth[ulp_u]==depth[ulp_v])
            ++depth[ulp_u];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        prnt.resize(n,-1);
        depth.resize(n,0);
        vector<int>cost(n,-1);
        for(auto it:edges)
            UnionByDepth(it[0],it[1]);
        for(auto it:edges)
        {
            int ulp_node=findUPar(it[0]);
            cost[ulp_node]&=it[2];
        }
        vector<int>ans;
        for(auto it:query)
        {
            int u=it[0],v=it[1];
            if(findUPar(u)!=findUPar(v))
                ans.push_back(-1);
            else
            {
                int ulp_node=findUPar(u);
                ans.push_back(cost[ulp_node]);
            }
        }
        return ans;
    }
};