class Solution {
public:

    void dfs(int node,vector<int>&vis,vector<vector<int>>adj,vector<int>&temp)
    {
        vis[node]=1;
        //vector<int>temp;
        temp.push_back(node);
        for(int i:adj[node])
        {
            //temp.push_back(i);
            if(!vis[i])
                dfs(i,vis,adj,temp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        if(n==1)
            return 1;
        if(edges.size()==0)
            return n;
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int>vis(n,0);
        vector<vector<int>>graph;
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                vector<int>temp;
                dfs(i,vis,adj,temp);
                graph.push_back(temp);
            }
        }
        for(auto i:graph)
        {
            // for(auto j:i)
            //     cout<<j<<" ";
            // cout<<"\n";
            int vert=i.size();
            //cout<<vert<<"\n";
            int edge=0;
            for(auto j:i)
            {
                for(auto it:adj[j])
                    ++edge;
            }
            //cout<<edge<<"\n";
            if(edge==0 && vert==1)
            {
                ++ans;
                continue;
            }
            if(edge==(vert*(vert-1)))
                ++ans;
        }
        return ans;
    }
};