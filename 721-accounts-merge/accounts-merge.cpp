class DisjointSetUnion
{
public:
    vector<int>prnt,size;
    DisjointSetUnion(int n)
    {
        prnt.resize(n+1,0);
        size.resize(n+1,0);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //Step - 1) Union Join
        int n=accounts.size();
        DisjointSetUnion dsu(n);
        unordered_map<string,int>mapMailNode;
        for(int i=0;i<n;++i)
        {
            for(int j=1;j<accounts[i].size();++j)
            {
                if(mapMailNode.find(accounts[i][j])==mapMailNode.end())
                    mapMailNode[accounts[i][j]]=i;
                else
                    dsu.UnionBySize(i,mapMailNode[accounts[i][j]]);
            }
        }
        //Step - 2) Mail merging as per ultimate parent
        vector<string>mail[n];
        for(auto it:mapMailNode)
        {
            string name=it.first;
            int parent=dsu.findUPar(it.second);
            mail[parent].push_back(name);
        }
        //Step - 3) Sort and arrange as per answer
        vector<vector<string>>ans;
        for(int i=0;i<n;++i)
        {
            if(mail[i].size()==0)
                continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(mail[i].begin(),mail[i].end());
            for(string it:mail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};