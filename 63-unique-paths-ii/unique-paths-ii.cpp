class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>pre(m,0);
        for(int i=0;i<m;++i)
        {
            if(grid[0][i]==1)
                break;
            pre[i]=1;
        }
        for(int i=1;i<n;++i)
        {
            vector<int>cur(m,0);
            cur[0]=pre[0];
            for(int j=0;j<m;++j)
            {
                int up=pre[j],left=0;
                if(j>=1)
                    left=cur[j-1];
                cur[j]=grid[i][j]==1?0:(up+left);
            }
            swap(pre,cur);
        }
        return pre[m-1];
    }
};