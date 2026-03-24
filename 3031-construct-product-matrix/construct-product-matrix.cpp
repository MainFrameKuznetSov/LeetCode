#define ll long long
#define MOD 12345

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        ll left=1,right=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ans[i][j]=left;
                left=(left*grid[i][j])%MOD;
            }
        }
        for(int i=n-1;i>=0;--i)
        {
            for(int j=m-1;j>=0;--j)
            {
                ans[i][j]=(ans[i][j]*right)%MOD;
                right=(right*grid[i][j])%MOD;
            }
        }
        return ans;
    }
};