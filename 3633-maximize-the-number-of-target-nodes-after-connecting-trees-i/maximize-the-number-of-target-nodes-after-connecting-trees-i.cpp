class Solution {
private:

    int tot(vector<vector<int>>&edges) 
    {
        int mx=0;
        for(auto it:edges)
            mx=max(mx,max(it[0],it[1]));
        return mx+1;
    }

    vector<vector<int>> adjgen(int n,vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        for(auto it:edges) 
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int bfs(vector<vector<int>>&adj,int start,int maxd) 
    {
        vector<int>dist(adj.size(),-1);
        queue<int>q;
        q.push(start);
        dist[start]=0;
        int cnt=1;
 
        while(!q.empty()) 
        {
            int curr=q.front();
            q.pop();
 
            if(dist[curr]==maxd) 
                    continue;
 
            for(auto nxt:adj[curr]) 
            {
                if(dist[nxt]==-1) 
                {
                    dist[nxt]=dist[curr]+1;
                    if(dist[nxt]<=maxd) 
                    {
                        ++cnt;
                        q.push(nxt);
                    }
                }
            }
        }
        return cnt;
    }

    vector<int> Count(int n,vector<vector<int>>&adj,int maxd) 
    {
        vector<int>ans(n);
        for(int i=0;i<n;++i)
            ans[i]=bfs(adj,i,maxd);
        return ans;
    }

    int getmax(vector<int>&v) 
    {
        if(v.size()==0)
            return 0;
        return(*max_element(v.begin(),v.end()));
    }

    struct Tree 
    {
        vector<vector<int>>edges1,edges2;
        int k;
    };
    Tree tree;

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        tree={edges1,edges2,k};
        int t1=tot(edges1),t2=tot(edges2);
        vector<vector<int>>adj1=adjgen(t1,edges1);
        vector<vector<int>>adj2=adjgen(t2,edges2);
        vector<int>found=Count(t1,adj1,k);
        int max2=0;
        if(k>0) 
        {
            vector<int>found2=Count(t2,adj2,k-1);
            max2=getmax(found2);
        }
        vector<int>ans(t1);
        for(int i=0;i<t1;++i)
            ans[i]=found[i]+max2;
 
        return ans;
    }
};