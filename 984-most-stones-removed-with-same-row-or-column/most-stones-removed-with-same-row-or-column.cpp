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
        else
            return prnt[u]=findUPar(prnt[u]);
    }
    void UnionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size(),mR=0,mC=0;
        for(auto it:stones)
        {
            mR=max(mR,it[0]);
            mC=max(mC,it[1]);
        }
        DisjointSetUnion dsu(mR+mC+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones)
        {
            int nr=it[0],nc=it[1]+mR+1;
            dsu.UnionBySize(nr,nc);
            stoneNodes[nr]=1;
            stoneNodes[nc]=1;
        }
        int comp=0;
        for(auto it:stoneNodes)
        {
            if(dsu.prnt[it.first]==it.first)
                ++comp;
        }
        return (n-comp);
    }
};