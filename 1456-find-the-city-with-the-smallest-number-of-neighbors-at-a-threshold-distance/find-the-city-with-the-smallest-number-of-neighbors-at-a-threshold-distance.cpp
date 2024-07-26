class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;++i) 
            distance[i][i]=0;
        for(auto iter:edges)
        {
            distance[iter[0]][iter[1]]=iter[2];
            distance[iter[1]][iter[0]]=iter[2];
        }
        for(int k=0;k<n;++k)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX)
                        distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
        int minCount=INT_MAX;
        int edge=-1;
        for(int i=0;i<n;++i)
        {
            int count=0;
            for(int j=0;j<n;++j)
            {
                if(i==j) 
                    continue;
                count+=(distanceThreshold>=distance[i][j]);
            }
            if(count<=minCount)
            { 
                edge=i;
                minCount=count;
            }
        }
        return edge;
    }
};