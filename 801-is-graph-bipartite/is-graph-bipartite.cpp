class Solution {

private:
    bool check(int start,vector<int>&color,vector<vector<int>>&graph)
    {
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    //col=1-col;
                    q.push(it);
                }
                else
                {
                    if(color[it]==color[node])
                        return 0;
                }
                //q.push(it);
            }
        }
        return 1;
    }
    
    bool dfs(int start,int col,vector<int>&color,vector<vector<int>>&graph)
    {
        color[start]=col;
        for(auto it:graph[start])
        {
            if(color[it]==-1)
            {
                if(!dfs(it,1-col,color,graph))
                    return 0;
            }
            else if(color[it]==color[start])
                return 0;
        }
        return 1;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;++i)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,0,color,graph))
                    return 0;
            }
        }
        return 1;
    }
};