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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,nums,-1,dp);
    }
};