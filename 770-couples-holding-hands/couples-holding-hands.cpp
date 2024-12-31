class DisjointSet 
{
    vector<int>rank,size,prnt;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        prnt.resize(n+1);
    }

    void makePar(int c,int p)
    {
        prnt[c]=p;
    }

    int findUPar(int u)
    {
        if(u==prnt[u])
            return u;
        return prnt[u]=findUPar(prnt[u]);
    }

    bool find(int u, int v) {
        return findUPar(u)==findUPar(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return ;
        if(rank[ulp_u]<rank[ulp_v])
            prnt[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v])
            prnt[ulp_v]=ulp_u;
        else
        {
            prnt[ulp_v]=ulp_u;
            ++rank[ulp_u];
        }
    }

    bool Union(int a,int b)
    {
        int ulp_a=findUPar(a),ulp_b=findUPar(b);
        if(ulp_a==ulp_b)
            return 0;
        prnt[ulp_a]=ulp_b;
        return 1;
    }

    void unionBySize(int u, int v) {
       int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v)    
                return ;
            if(size[ulp_u]<size[ulp_v])
            {
                prnt[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else
            {
                prnt[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
    }
};


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size(),ans=0;
        if(n==0)
            return 0;
        DisjointSet DSU(n);
        for(int i=0;i<row.size();i+=2)
        {
            DSU.makePar(row[i],row[i]);
            DSU.makePar(row[i+1],row[i]);
        }
        for(int i=0;i<row.size();i+=2)
        {
            if(DSU.Union(i,i+1))
                ++ans;
        }
        return ans;
    }
};