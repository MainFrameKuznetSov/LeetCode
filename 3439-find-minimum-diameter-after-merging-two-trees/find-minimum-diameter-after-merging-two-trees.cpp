class Solution {
private:
    void create(vector<vector<int>>&adj,vector<vector<int>>&edges,int n)
    {
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    void fetch(pair<int,int>&p,vector<vector<int>>&adj,int node,int dis,vector<int>&vis)
    {
        vis[node]=1;
        if(dis>p.second)
        {
            p.second=dis;
            p.first=node;
        }
        for(auto it: adj[node])
        {
            if(!vis[it])
                fetch(p,adj,it,dis+1,vis);
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);

        create(adj1,edges1,n);
        create(adj2,edges2,m);

        vector<int>vis(n);
        pair<int,int>p1={-1,INT_MIN};
        fetch(p1,adj1,0,0,vis);
        vis=vector<int>(n,0);
        pair<int,int>p2={-1,INT_MIN};
        fetch(p2,adj1,p1.first,0,vis);

        int d1=p2.second;
        p1={-1,INT_MIN};
        vis=vector<int>(m,0);
        fetch(p1,adj2,0,0,vis);
        p2={-1,INT_MIN};
        vis=vector<int>(m, 0);
        fetch(p2,adj2,p1.first,0,vis);

        int d2=p2.second;
        if(edges1.empty()) 
            d1=0;
        if(edges2.empty()) 
            d2=0;
        return max(d1,max(d2,(d1+1)/2+(d2+1)/2+1));
    }
};