class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(n,0);
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            ++indeg[v];
        }
        queue<int>q;
        vector<vector<int>>temp(n,vector<int>(26,0));
        for(int i=0;i<n;++i)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                temp[i][colors[i]-'a']=1;
            }
        }
        int ans=0,cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ++cnt;
            ans=max(ans,temp[node][colors[node]-'a']);
            for(int it:adj[node])
            {
                for(int i=0;i<26;++i)
                    temp[it][i]=max(temp[it][i],temp[node][i]+(colors[it]-'a'==i));
                --indeg[it];
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        if(cnt<n)
            return -1;
        return ans;
    }
};