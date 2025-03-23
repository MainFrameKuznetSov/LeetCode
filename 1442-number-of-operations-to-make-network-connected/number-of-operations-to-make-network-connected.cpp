class DisjointSet
{
    public:
        vector<int>prnt,size;
        int components;
        DisjointSet(int n)
        {
            components=n;
            prnt.resize(n,0);
            size.resize(n,1);
            for(int i=0;i<n;++i)
                prnt[i]=i;
        }

        int findUPar(int u)
        {
            if(prnt[u]==u)
                return u;
            return prnt[u]=findUPar(prnt[u]);
        }

        int unionBySize(int u,int v)
        {
            int ulp_u=findUPar(u),ulp_v=findUPar(v);
            if(ulp_u==ulp_v)
                return 1;
            if(size[ulp_u]>size[ulp_v])
            {
                size[ulp_u]+=size[ulp_v];
                prnt[ulp_v]=ulp_u;
                --components;
            }
            else
            {
                size[ulp_v]+=size[ulp_u];
                prnt[ulp_u]=ulp_v;
                --components;
            }
            return 0;
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dsu(n);
        int extra=0,pre=n;
        for(auto it:connections)
        {
            int u=it[0],v=it[1];
            //if(dsu.prnt[u]!=dsu.prnt[v])
            extra+=dsu.unionBySize(u,v);
            // else
            // {
            //     //cout<<u<<"-->"<<v<<"\n";
            //     dsu.unionBySize(u,v);
            //     ++extra;
            // }
            //cout<<u<<"-->"<<v<<" "<<dsu.components<<"\n";
        }
        int ans=dsu.components;
        //cout<<ans<<" "<<extra<<"\n";
        if(extra+1<ans)
            return -1;
        return ans-1;
    }
};