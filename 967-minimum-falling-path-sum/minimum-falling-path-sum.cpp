class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
            dp[0][i]=matrix[0][i];
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int up=matrix[i][j],rd=matrix[i][j],ld=matrix[i][j];
                up+=dp[i-1][j];
                if(j>0)
                    ld+=dp[i-1][j-1];
                else
                    ld=INT_MAX;
                if(j<n-1)
                    rd+=dp[i-1][j+1];
                else
                    rd=INT_MAX;
                dp[i][j]=min(up,min(ld,rd));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;++i)
            ans=min(ans,dp[n-1][i]);
        return ans;
    }
};