class DisjointSetUnion
{
public:
    vector<int>prnt,size;
    DisjointSetUnion(int n)
    {
        prnt.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;++i)
            prnt[i]=i;
    }

    int findUPar(int u)
    {
        if(prnt[u]==u)
            return u;
        return prnt[u]=findUPar(prnt[u]);
    }

    void UnionBySize(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return ;
        if(size[ulp_u]>size[ulp_v])
        {
            prnt[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            prnt[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]==1 && i!=j)
                    adj[i].push_back(j);
            }
        }
        DisjointSetUnion dsu(n);
        for(int i=0;i<n;++i)
        {
            for(auto it:adj[i])
                dsu.UnionBySize(i,it);
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(dsu.prnt[i]==i)
                ++ans;
        }
        return ans;
    }
};