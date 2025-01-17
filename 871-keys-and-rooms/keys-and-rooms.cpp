class Solution {
public:

    void dfs(int node,vector<bool>&vis,vector<vector<int>>rooms)
    {
        vis[node]=1;
        for(auto it:rooms[node])
        {
            if(!vis[it])
                dfs(it,vis,rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,0);
        vis[0]=1;
        for(int i=0;i<n;++i)
        {
            if(vis[i])
                dfs(i,vis,rooms);
        }
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
                return 0;
        }
        return 1;
    }
};