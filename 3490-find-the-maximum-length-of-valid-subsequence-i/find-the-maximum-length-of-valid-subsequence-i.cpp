class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>>dp(2,vector<int>(2,0));
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<2;++j)
            {
                int rem=nums[i]%2;
                dp[rem][j]=dp[j][rem]+1;
                ans=max(ans,dp[rem][j]);
            }
        }
        return ans;
    }
};