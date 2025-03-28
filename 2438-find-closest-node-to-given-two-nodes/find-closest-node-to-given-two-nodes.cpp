class Solution {
public:

    vector<int> distance(int node,vector<int>adj[],int n)
    {
        vector<int>dist(n,INT_MAX);
        dist[node]=0;
        queue<pair<int,int>>q;
        q.push({0,node});
        while(!q.empty())
        {
            int dis=q.front().first,node=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int nextNode=it;
                if(dis+1<dist[nextNode])
                {
                    dist[nextNode]=dis+1;
                    q.push({dis+1,nextNode});
                }
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;++i)
        {
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        vector<int>v1=distance(node1,adj,n),v2=distance(node2,adj,n);
        int ans=-1,minDist=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(v1[i]!=INT_MAX && v2[i]!=INT_MAX && max(v1[i],v2[i])<minDist)
            {
                minDist=max(v1[i],v2[i]);
                ans=i;
            }
        }
        return ans;
    }
};