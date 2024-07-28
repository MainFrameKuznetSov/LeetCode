class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto iter:edges)
        {
            int u=iter[0],v=iter[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>minDist(n+1,INT_MAX);
        vector<int>secondMinDist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({1,0});
        minDist[1]=0;
        while(!pq.empty())
        {
            auto curr = pq.top();
            int currVertex = curr.first;
            int currTime = curr.second;
            pq.pop();
            for(auto iter:adj[currVertex])
            {
                int travelTime=currTime+time;
                if((currTime/change)%2==1)
                    travelTime+=(change-(currTime%change));
                if(travelTime<minDist[iter])
                {
                    secondMinDist[iter]=minDist[iter];
                    minDist[iter]=travelTime;
                    pq.push({iter,minDist[iter]});
                }
                else if(travelTime>minDist[iter] && travelTime<secondMinDist[iter])
                {
                    secondMinDist[iter]=travelTime;
                    pq.push({iter,secondMinDist[iter]});
                }
            }
        }
        return secondMinDist[n];
    }
};