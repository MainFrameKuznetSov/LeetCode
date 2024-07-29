class Solution {
public:
    int numberOfArrays(string s, int k) {
        int i,j,n=s.length(),mod=1e9+7;
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(i=n-1;i>=0;--i)
        {
            long long ways=0,num=0;
            for(j=i;j<n;++j)
            {
                int dig=s[j]-'0';
                num=10*num+dig;
                if(num<1 || num>k) 
                    break;
                ways=(ways+dp[j+1])%mod;
            }
            dp[i]=ways;
        }
        return dp[0];
    }
};