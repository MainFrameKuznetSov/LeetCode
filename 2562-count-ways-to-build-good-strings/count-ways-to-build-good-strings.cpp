class Solution {
public:

    int MOD=1e9+7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(100001,0);
        dp[0]=1;
        for(int i=1;i<=high;++i)
        {
            long long sum=1;
            if(i>=zero)
                sum+=dp[i-zero];
            if(i>=one)
                sum+=dp[i-one];
            dp[i]=sum%MOD;
        }
        return (dp[high]-dp[low-1]+MOD)%MOD;
    }
};