class Solution {
public:

    long long f(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        long long mn=INT_MIN;
        for(int k=i;k<=j;++k)
        {
            long long cost=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            mn=max(mn,cost);
        }
        return dp[i][j]=mn;
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        //return f(1,<n-2,nums,dp);
        for(int i=n;i>=1;--i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i>j)
                    continue;
                int mx=INT_MIN;
                for(int k=i;k<=j;++k)
                {
                    int cost=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    mx=max(cost,mx);
                }
                dp[i][j]=mx;
            }
        }
        return dp[1][n];
    }
};