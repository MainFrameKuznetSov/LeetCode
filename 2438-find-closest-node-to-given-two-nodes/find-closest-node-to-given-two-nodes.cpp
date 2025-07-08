class Solution {
public:

    vector<int>distance(vector<int>&edges,int node)
    {
        int n=edges.size();
        vector<int>dist(n,INT_MAX);
        dist[node]=0;
        queue<pair<int,int>>q;
        q.push({0,node});
        while(!q.empty())
        {
            int dis=q.front().first,nd=q.front().second;
            q.pop();
            int it=edges[nd];
            if(it==-1)
                continue;
            if(dis+1<dist[it])
            {
                dist[it]=dis+1;
                q.push({dis+1,it});
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>v1=distance(edges,node1),v2=distance(edges,node2);
        int ans=INT_MAX,maxDist=INT_MAX,n=edges.size();
        for(int i=0;i<n;++i)
        {
            if(v1[i]!=INT_MAX && v2[i]!=INT_MAX)
            {
                int temp=max(v1[i],v2[i]);
                if(temp<maxDist)
                {
                    maxDist=temp;
                    ans=i;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};