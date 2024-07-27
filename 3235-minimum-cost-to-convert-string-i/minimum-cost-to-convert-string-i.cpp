class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<long long>>graph(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<n;++i) 
            graph[original[i]-'a'][changed[i]-'a']=min(graph[original[i] - 'a'][changed[i]-'a'],(long long)cost[i]);
        for(int k=0;k<26;++k) 
        {
            for(int i=0;i<26;++i) 
            {
                for(int j=0;j<26;++j) 
                {
                    if ((graph[k][j]!=INT_MAX && graph[i][k]!=INT_MAX) && graph[i][j]>(long long)(graph[i][k]+graph[k][j]))
                       graph[i][j]=(long long)(graph[i][k]+graph[k][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();++i) 
        {
            int a=source[i]-'a';
            int b=target[i]-'a';
            if(a!=b) 
            {
                if(graph[a][b]==INT_MAX) 
                    return -1;
                ans=(long long)(ans+graph[a][b]);
            }
        }
        return ans;
    }
};