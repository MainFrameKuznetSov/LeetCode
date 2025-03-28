class Solution {
public:

    typedef pair<int,int> pii;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)
            return 0;
        queue<pii>q;
        set<pii>vis;
        for(int i=0;i<n;++i)
        {
            q.push({i,1<<i});
            vis.insert({i,1<<i});
        }
        int dest=(1<<n)-1;
        int path=0;
        while(!q.empty())
        {
            int size=q.size();
            ++path;
            while(size--)
            {
                auto curr=q.front();
                q.pop();
                int node=curr.first,mask=curr.second;
                for(auto it:graph[node])
                {
                    int nextMask=mask|(1<<it);
                    if(nextMask==dest)
                        return path;
                    if(!vis.count({it,nextMask}))
                    {
                        q.push({it,nextMask});
                        vis.insert({it,nextMask});
                    }
                }
            }
        }
        return -1;
    }
};