class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,0);
        for(int i=n-1;i>=0;--i)
        {
            auto it=questions[i];
            int sum=i+it[1]+1;
            if(sum<n)
                dp[i]=dp[sum]+it[0];
            else
                dp[i]=it[0];
            if(i<n-1)
                dp[i]=max(dp[i+1],dp[i]);
        }
        return dp[0];
    }
};