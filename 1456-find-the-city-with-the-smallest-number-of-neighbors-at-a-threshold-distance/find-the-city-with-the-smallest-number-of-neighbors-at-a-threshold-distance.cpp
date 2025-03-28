class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }
        
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<n;++j)
        //         cout<<mat[i][j]<<" ";
        //     cout<<"\n\n";
        // }

        for(int i=0;i<n;++i)
        {
            mat[i][i]=0;
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(mat[j][i]!=INT_MAX && mat[i][k]!=INT_MAX)
                        mat[j][k]=min(mat[j][k],mat[j][i]+mat[i][k]);
                }
            }
        }
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<n;++j)
        //         cout<<mat[i][j]<<" ";
        //     cout<<"\n";
        // }
        int ans=-1,mncnt=INT_MAX;
        for(int i=0;i<n;++i)
        {
            int cnt=0;
            for(int j=0;j<n;++j)
            {
                if(i!=j && mat[i][j]<=distanceThreshold)
                    ++cnt;
            }
            //cout<<i<<" "<<cnt<<"\n";
            if(cnt<=mncnt)
            {
                mncnt=cnt;
                ans=i;
            }
        }
        return ans;
    }
};