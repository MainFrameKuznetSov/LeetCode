class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0);
        prob[start]=1;
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        pq.push({1,start});
        while(!pq.empty())
        {
            double pro=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto iter:adj[node])
            {
                int nextNode=iter.first;
                double chance=iter.second;
                if((chance*pro)>prob[nextNode])
                {
                    prob[nextNode]=chance*pro;
                    pq.push({prob[nextNode],nextNode});
                }
            }
        }
        return prob[end];
    }
};