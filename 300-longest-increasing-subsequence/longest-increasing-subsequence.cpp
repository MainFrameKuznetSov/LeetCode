class Solution {
public:

    int f(int ind,vector<int>&nums,int prev,vector<vector<int>>&dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        int notTake=f(ind+1,nums,prev,dp),Take=0;
        if(prev==-1 || nums[ind]>nums[prev])
            Take=1+f(ind+1,nums,ind,dp);
        return dp[ind][prev+1]=max(Take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //return f(0,nums,-1,dp);
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i-1;j>=-1;--j)
            {
                int notTake=dp[i+1][j+1],Take=0;
                if(j==-1 || nums[i]>nums[j])
                    Take=1+dp[i+1][i+1];
                dp[i][j+1]=max(Take,notTake);
            }
        }
        return dp[0][0];
    }
};