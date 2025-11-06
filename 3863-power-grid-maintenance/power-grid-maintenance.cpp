class DisjointSet
{
private:
    vector<int>prnt,size;
    int comp;

public:
    DisjointSet(int n): prnt(n+1),size(n+1,1),comp(n)
    {
        for(int i=0;i<=n;++i)
            prnt[i]=i;
    }

    int findUPar(int x)
    {
        if(prnt[x]!=x)
            prnt[x]=findUPar(prnt[x]);
        return prnt[x];
    }

    void Union(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return ;
        if(size[ulp_u]<size[ulp_v])
            swap(ulp_u,ulp_v);
        prnt[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
        --comp;
    }

    int getComp()
    {
        return comp;
    }
    
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DisjointSet dsu(c);
        for(auto it:connections)
            dsu.Union(it[0],it[1]);

        unordered_map<int,int>mp;
        vector<int>ind(c+1);
        int ptr=0;

        for(int i=1;i<=c;++i)
        {
            int ulp_i=dsu.findUPar(i);
            if(!mp.count(ulp_i))
                mp[ulp_i]=ptr++;
            ind[i]=mp[ulp_i];
        }

        vector<set<int>>st(ptr);
        vector<bool>vis(c+1,1);
        for(int i=1;i<=c;++i)
            st[ind[i]].insert(i);

        vector<int>ans;
        for(auto it:queries)
        {
            int F=it[0],S=it[1],temp=ind[S];
            if(F==2)
            {
                if(vis[S])
                {
                    vis[S]=0;
                    st[temp].erase(S);
                }
            }
            else
            {
                if(vis[S])
                    ans.push_back(S);
                else
                {
                    auto &cont=st[temp];
                    if(!cont.empty())
                        ans.push_back(*cont.begin());
                    else
                        ans.push_back(-1);
                }
            }
        }

        return ans;
        
    }
};