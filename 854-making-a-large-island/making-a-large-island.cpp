class DisjointSet
{
    public:
        vector<int>prnt,size;
        int components;
        DisjointSet(int n)
        {
            components=n;
            prnt.resize(n,-1);
            size.resize(n,1);
            for(int i=0;i<n;++i)
                prnt[i]=i;
        }

        int getComponents()
        {
            return components;
        }

        int findUPar(int u)
        {
            if(prnt[u]==u)
                return u;
            return prnt[u]=findUPar(prnt[u]);
        }

        void unionBySize(int u,int v)
        {
            int ulp_u=findUPar(u),ulp_v=findUPar(v);
            if(ulp_u==ulp_v)
                return ;
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
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet dsu(n*n);
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
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj])
                        dsu.unionBySize(i*n+j,ni*n+nj);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j])
                    continue;
                unordered_set<int>st;
                for(int k=0;k<4;++k)
                {
                    int ni=i+dir[k].first,nj=j+dir[k].second;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj])
                    {
                        st.insert(dsu.findUPar(ni*n+nj));
                        //cout<<ni<<" "<<nj<<"\n";
                    }
                }
                int newSize=1;
                for(auto it:st)
                    newSize+=dsu.size[it];
                //cout<<newSize<<"\n";
                ans=max(ans,newSize);
                st.clear();
            }
        }
        for(int i=0;i<n*n;++i)
            ans=max(ans,dsu.size[dsu.prnt[i]]);
        return ans;
    }
};