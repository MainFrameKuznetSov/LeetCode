class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
            dp[n-1][i]=triangle[n-1][i];
        for(int i=n-2;i>=0;--i)
        {
            for(int j=i;j>=0;--j)
            {
                int d=triangle[i][j],rd=triangle[i][j];
                d+=dp[i+1][j];
                rd+=dp[i+1][j+1];
                dp[i][j]=min(d,rd);
            }
        }
        return dp[0][0];
    }
};