class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),ans=1;
        vector<vector<int>>dp(301,vector<int>(301,0));
        for(int i=n-1;i>=0;--i)
        {
            for(int j=1;j<=300;++j)
            {
                int diff=abs(j-nums[i]);
                dp[nums[i]][diff]=max(dp[nums[i]][diff],1+dp[j][diff]);
            }
            for(int j=1;j<=300;++j)
                dp[nums[i]][j]=max(dp[nums[i]][j],dp[nums[i]][j-1]);
        }

        for(int i=1;i<=300;++i)
        {
            for(int j=1;j<=300;++j)
                ans=max(ans,dp[i][j]);
        }

        return ans;

    }
};