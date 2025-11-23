class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3,INT_MIN);
        dp[0]=0;
        for(int i:nums)
        {
            vector<int>cpy=dp;
            for(int rem=0;rem<=2;++rem)
            {
                int nrem=(rem+i)%3;
                cpy[nrem]=max(cpy[nrem],dp[rem]+i);
            }
            dp=cpy;
        }
        return dp[0];
    }
};