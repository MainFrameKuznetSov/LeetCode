class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            dist[it[1]][it[0]]=it[2];
            dist[it[0]][it[1]]=it[2];
        }
        for(int i=0;i<n;++i)
        {
            dist[i][i]=0;
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(dist[j][i]!=INT_MAX && dist[i][k]!=INT_MAX) 
                        dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }

        int ans=-1,maxEdge=INT_MAX;

        for(int i=0;i<n;++i)
        {
            int cnt=0;
            for(int j=0;j<n;++j)
            {
                if(i!=j && dist[i][j]<=distanceThreshold)
                    ++cnt;
            }
            if(cnt<=maxEdge)
            {
                maxEdge=cnt;
                ans=i;
            }
        }

        return ans;
    }
};