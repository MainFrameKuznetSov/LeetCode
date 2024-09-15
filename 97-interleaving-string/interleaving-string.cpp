class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size(),b=s2.size(),c=s3.size();
        if(c!=a+b)
            return false;
        if(a<b)
            return isInterleave(s2,s1,s3);
        vector<bool>dp(b+1,false);
        dp[0]=1;
        for(int i=1;i<=b;++i)
            dp[i]=dp[i-1]&&s2[i-1]==s3[i-1];
        for(int i=1;i<=a;++i)
        {
            dp[0]=dp[0]&&s1[i-1]==s3[i-1];
            for(int j=1;j<=b;++j)
                dp[j]=(dp[j]&&s1[i-1]==s3[i+j-1]) || (dp[j-1]&&s2[j-1]==s3[i+j-1]);
        }
        return dp[b];
    }
};