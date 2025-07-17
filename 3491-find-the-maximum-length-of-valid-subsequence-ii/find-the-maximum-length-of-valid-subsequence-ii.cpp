class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<k;++j)
            {
                int rem=nums[i]%k;
                dp[rem][j]=dp[j][rem]+1;
                ans=max(ans,dp[rem][j]);
            }
        }
        return ans;
    }
};