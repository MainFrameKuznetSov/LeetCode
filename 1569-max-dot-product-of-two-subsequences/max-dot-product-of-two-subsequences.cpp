#define INF -1e9

class Solution {
public:

    int n,m;

    int f(int ind1,int ind2,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(ind1==n || ind2==m)
            return INF;
        if(dp[ind1][ind2]!=INF)
            return dp[ind1][ind2];
        int Take=nums1[ind1]*nums2[ind2];
        int ans=max({Take,
                     Take+f(ind1+1,ind2+1,nums1,nums2,dp),
                     f(ind1+1,ind2,nums1,nums2,dp),
                     f(ind1,ind2+1,nums1,nums2,dp)});
        return dp[ind1][ind2]=ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->n=nums1.size();
        this->m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,INF));
        return f(0,0,nums1,nums2,dp);
    }
};