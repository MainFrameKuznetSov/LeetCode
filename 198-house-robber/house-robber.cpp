#define INF (int)-1e9

class Solution {
public:

    // int f(int ind,vector<int>&nums,vector<int>&dp)
    // {
    //     if(ind<0)
    //         return 0;
    //     if(dp[ind]!=-1)
    //         return dp[ind];
    //     int notTake=f(ind-1,nums,dp),Take=0;
    //     Take=nums[ind]+f(ind-2,nums,dp);
    //     return dp[ind]=max(notTake,Take);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,0);
        dp[0]=dp[1]=0;
        for(int i=2;i<=n+1;++i)
        {
            int notTake=dp[i-1],Take=0;
            Take=nums[i-2]+dp[i-2];
            dp[i]=max(notTake,Take);
        }
        return dp[n+1];
    }
};