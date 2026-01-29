#define ll long long

class Solution {
public:
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<ll>>graph(26,vector<ll>(26,INT_MAX));
        for(int i=0;i<n;++i) 
            graph[original[i]-'a'][changed[i]-'a']=min(graph[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        for(int k=0;k<26;++k) 
        {
            for(int i=0;i<26;++i) 
            {
                for(int j=0;j<26;++j) 
                {
                    if ((graph[k][j]!=INT_MAX && graph[i][k]!=INT_MAX) 
                      && graph[i][j]>(ll)(graph[i][k]+graph[k][j]))
                       graph[i][j]=(ll)(graph[i][k]+graph[k][j]);
                }
            }
        }
        ll ans=0;
        for(int i=0;i<source.size();++i) 
        {
            int a=source[i]-'a',b=target[i]-'a';
            if(a!=b) 
            {
                if(graph[a][b]==INT_MAX) 
                    return -1;
                ans=(ll)(ans+graph[a][b]);
            }
        }
        return ans;
    }
};