class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>prev(n,-1);
        for(int i=0;i<n;++i)
            prev[i]=grid[0][i];
        int ans=INT_MAX;
        for(int i=1;i<n;++i)
        {
            vector<int>curr(n,-1);
            for(int j=0;j<n;++j)
            {
                int mn=INT_MAX;
                for(int k=0;k<n;++k)
                {
                    if(k!=j) 
                        mn=min(mn,grid[i][j]+prev[k]);
                    curr[j]=mn;
                }
            }
            prev=curr;
        }
        for(int i=0;i<n;++i)
            ans=min(ans,prev[i]);
        return ans;
    }
};