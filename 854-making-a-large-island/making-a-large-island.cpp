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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSetUnion dsu(n*n);
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==0)
                    continue;
                for(int k=0;k<4;++k)
                {
                    int ni=i+dir[k].first,nj=j+dir[k].second;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1)
                        dsu.UnionBySize(i*n+j,ni*n+nj);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                unordered_set<int>st;
                if(grid[i][j]==0)
                {
                    for(int k=0;k<4;++k)
                    {
                        int ni=i+dir[k].first,nj=j+dir[k].second;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1)
                            st.insert(dsu.findUPar(ni*n+nj));
                    }
                }
                else
                    continue;
                int temp=0;
                for(auto it:st)
                    temp+=dsu.size[it];
                ans=max(ans,temp+1);
            }
        }
        for(int i=0;i<n*n;++i)
            ans=max(ans,dsu.size[dsu.findUPar(i)]);
        return ans;
    }
};