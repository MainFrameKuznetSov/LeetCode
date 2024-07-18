class Solution {
public:
    int memo(int ind,int prev,int n,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        int len=memo(ind+1,prev,n,arr,dp);
        if(prev==-1 || arr[ind]>arr[prev])
            len=max(len,1+memo(ind+1,ind,n,arr,dp));
        return dp[ind][prev+1]=len;
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(0,-1,n,nums,dp);
    }
};