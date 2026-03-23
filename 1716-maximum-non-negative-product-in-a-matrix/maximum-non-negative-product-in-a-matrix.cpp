#define MOD 1000000007
#define ll long long

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<ll>>dp1(n,vector<ll>(m,0)),dp2(n,vector<ll>(m,0));
        dp1[0][0]=dp2[0][0]=grid[0][0];
        for(int i=1;i<n;++i)
            dp1[i][0]=dp2[i][0]=dp2[i-1][0]*grid[i][0];
        for(int i=1;i<m;++i)
            dp1[0][i]=dp2[0][i]=dp2[0][i-1]*grid[0][i];
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                ll ch1=dp1[i-1][j]*grid[i][j],ch2=dp2[i-1][j]*grid[i][j];
                ll ch3=dp1[i][j-1]*grid[i][j],ch4=dp2[i][j-1]*grid[i][j];
                dp1[i][j]=min({ch1,ch2,ch3,ch4});
                dp2[i][j]=max({ch1,ch2,ch3,ch4});
            }
        }
        if(dp2[n-1][m-1]<0)
            return -1;
        return dp2[n-1][m-1]%MOD;
    }
};