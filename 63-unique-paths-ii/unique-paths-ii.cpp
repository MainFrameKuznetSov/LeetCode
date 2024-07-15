class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m=grid.size(),n=grid[0].size();
        /*if(m==1 && n==1)
        {   
            if(grid[0][0]==1)
                return 0;
            else
                return 1;
        }*/
        vector<int>prev(n,0);
        if(grid[0][0]==1)
            prev[0]=0;
        else
            prev[0]=1;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int up=0,left=0;
                if(i==0 && j==0)
                    continue;
                if(i>0 && grid[i][j]!=1)
                    up=prev[j];
                if(j>0 && grid[i][j]!=1)
                    left=prev[j-1];
                prev[j]=up+left;
            }
            //prev=curr;
        }
        return prev[n-1];
    }
};