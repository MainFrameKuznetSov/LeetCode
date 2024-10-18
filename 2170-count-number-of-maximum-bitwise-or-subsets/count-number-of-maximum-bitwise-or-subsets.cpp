class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0,cnt=0;
        for(int i:nums)
            mx|=i;
        vector<int>dp(1<<17+1,0);
        dp[0]=1;
        for(int i:nums)
        {
            for(int msk=1<<17;msk>=0;--msk)
            {
                if(dp[msk]!=0)
                    dp[msk|i]+=dp[msk];
            }
        }
        return dp[mx];
    }
};