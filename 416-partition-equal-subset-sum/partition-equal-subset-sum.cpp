class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum&1)
            return 0;
        int tar=sum/2;
        vector<bool>dp(tar+1,0);
        dp[0]=1;
        for(int i:nums)
        {
            for(int j=tar;j>=i;--j)
            {
                dp[j]=dp[j]||dp[j-i];
                if(dp[tar])
                    return 1;
            }
        }
        return dp[tar];
    }
};