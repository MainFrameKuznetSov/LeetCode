class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<int>visR(n,0),visC(m,0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j])
                {
                    visR[i]++;
                    visC[j]++;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j] && (visR[i]>1 || visC[j]>1)) 
                    ++ans;
            }
        }
        return ans;
    }
};