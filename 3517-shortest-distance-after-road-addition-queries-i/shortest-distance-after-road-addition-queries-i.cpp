class Solution {
public:

    int bfs(vector<vector<int>>&vect,int n)
    {
        vector<int>dist(n,n);
        queue<int>que;
        dist[0]=0;
        que.push(0);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int iter:vect[u])
            {
                if(dist[iter]>dist[u]+1)
                {
                    dist[iter]=dist[u]+1;
                    que.push(iter);
                }
            }
        }
        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>res;
        vector<vector<int>>vect(n);
        for(int i=0;i<n-1;++i)
            vect[i].push_back(i+1);
        for(auto iter:queries)
        {
            vect[iter[0]].push_back(iter[1]);    
            res.push_back(bfs(vect,n));
        }
        return res;
    }
};