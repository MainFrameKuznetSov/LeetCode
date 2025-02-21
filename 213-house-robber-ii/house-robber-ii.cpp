class Solution {
public:

    int f(int ind,vector<int>v,vector<int>&dp)
    {   
        if(ind>=v.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int take=v[ind]+f(ind+2,v,dp);
        int notTake=f(ind+1,v,dp);
        return dp[ind]=max(take,notTake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>v1,v2;
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                v2.push_back(nums[i]);
            if(i!=n-1)
                v1.push_back(nums[i]);
        }
        vector<int>dp1(v1.size(),-1),dp2(v2.size(),-1);
        f(0,v1,dp1);
        f(0,v2,dp2);
        return max(dp1[0],dp2[0]);
    }
};