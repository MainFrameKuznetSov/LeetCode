class DSU
{
    vector<int>prnt,size;
public:
    DSU(int n)
    {
        size.resize(n+1,0);
        prnt.resize(n+1,0);
        for(int i=0;i<=n;++i)
            prnt[i]=i;
    }

    int getBef(int node)
    {
        if(node==prnt[node])
            return node;
        return prnt[node]=getBef(prnt[node]);
    }

    bool same(int x,int y)
    {
        return getBef(x)==getBef(y);
    }

    int Union(int x,int y)
    {
        int ux=getBef(x);
        int uy=getBef(y);
        if(ux==uy)
            return 0;
        if(size[ux]<size[uy])
        {
            prnt[ux]=uy;
            size[uy]+=size[ux];
        }
        else
        {
            prnt[uy]=ux;
            size[ux]+=size[uy];
        }
        return 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU ob1(n);
        DSU ob2(n);
        int A=0,B=0,temp=0;
        sort(edges.rbegin(),edges.rend());
        for(auto iter:edges)
        {
            int t=iter[0],u=iter[1],v=iter[2];
            if(t==2)
            {
                int rf=ob2.Union(u,v);
                B+=rf;
                temp+=rf;
            }
            else if(t==3)
            {
                int lf=ob1.Union(u,v);
                int rf=ob2.Union(u,v);
                A+=lf;
                B+=rf;
                if(lf|rf)
                    ++temp;
            }
            else
            {
                int lf=ob1.Union(u,v);
                A+=lf;
                temp+=lf;
            }
        }
        if(A!=n-1 || B!=n-1)
            return -1;
        return edges.size()-temp;
    }
};