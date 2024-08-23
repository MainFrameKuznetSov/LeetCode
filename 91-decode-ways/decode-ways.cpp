class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        vector<int>dp(len+1,0);
        dp[0]=1;
        if(s[0]!='0')
            dp[1]=1;
        else
            return 0;
        for (int i=2;i<=len;++i) 
        {
            if(s[i-1]!='0')
                dp[i]+=dp[i-1];
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))
                dp[i]+=dp[i-2];
        }
        return dp[len];
    }
};