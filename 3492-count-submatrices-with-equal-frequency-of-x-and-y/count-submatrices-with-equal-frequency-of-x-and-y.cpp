class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<int>>dpx(m+1,vector<int>(n+1,0));
        vector<vector<int>>dpy(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i) 
        {
            for(int j=1;j<=n;++j) 
            {
                dpx[i][j]=dpx[i-1][j]+dpx[i][j-1]-dpx[i-1][j-1];
                if(grid[i-1][j-1]=='X')
                    ++dpx[i][j];
                dpy[i][j]=dpy[i-1][j]+dpy[i][j-1]-dpy[i-1][j-1];
                if(grid[i-1][j-1]=='Y')
                    ++dpy[i][j];
            }
        }
        for(int i=0;i<m;++i) 
        {
            for(int j=0;j<n;++j) 
            {
                int X=dpx[i+1][j+1]+dpx[0][0]-dpx[0][j+1]-dpx[i+1][0];
                int Y=dpy[i+1][j+1]+dpy[0][0]-dpy[0][j+1]-dpy[i+1][0];
                if(X==Y && X>0)
                    ++ans;
            }
        }
        return ans;
    }
};