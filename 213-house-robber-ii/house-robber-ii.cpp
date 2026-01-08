class Solution {
public:

    int f(int ind,vector<int>&vec,vector<int>&dp)
    {
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int notTake=f(ind-1,vec,dp),Take=0;
        Take=f(ind-2,vec,dp)+vec[ind];
        return dp[ind]=max(notTake,Take);
    }

    int rob(vector<int>& nums) {
        vector<int>v1,v2;
        int n=nums.size();
        if(n==1)
            return nums[0];
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                v1.push_back(nums[i]);
            if(i!=n-1)
                v2.push_back(nums[i]);
        }
        vector<int>dp1(n,-1),dp2(n,-1);
        return max(f(v1.size()-1,v1,dp1),f(v2.size()-1,v2,dp2));
    }
};