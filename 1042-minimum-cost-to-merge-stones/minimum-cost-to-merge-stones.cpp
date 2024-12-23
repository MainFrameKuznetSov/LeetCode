class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1))
            return -1;
        vector<int>pre(n+1,0);
        for(int i=0;i<n;++i)
            pre[i+1]=pre[i]+stones[i];
        vector<vector<long long>>dp(n,vector<long long>(n,0));
        for(int i=k;i<=n;++i)
        {
            for(int j=0;j<=(n-i);++j)
            {
                int temp=j+i-1;
                dp[j][temp]=INT_MAX;
                for(int l=j;l<temp;l+=(k-1))
                    dp[j][temp]=min(dp[j][temp],dp[j][l]+dp[l+1][temp]);
                if((temp-j)%(k-1)==0)
                    dp[j][temp]+=pre[temp+1]-pre[j];
            }
        }
        return dp[0][n-1];
    }
};