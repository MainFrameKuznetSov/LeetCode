class Solution {
public:

    int prnt[26];

    int findUPar(int node)
    {
        if(prnt[node]==-1)
            return node;
        return prnt[node]=findUPar(prnt[node]);
    }

    void Union(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(ulp_u!=ulp_v)
            prnt[max(ulp_u,ulp_v)]=min(ulp_u,ulp_v);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(prnt,-1,sizeof(prnt));
        for(int i=0;i<s1.size();++i)
            Union(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<baseStr.size();++i)
            baseStr[i]=findUPar(baseStr[i]-'a')+'a';
        return baseStr;
    }
};