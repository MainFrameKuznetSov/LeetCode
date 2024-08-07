class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)
            return s;
        int len=0,left=0,right=0,n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i=0;i<n;++i)
        {
            dp[i][i]=1;
            for(int j=0;j<i;++j)
            {
                if(s[j]==s[i] && (i-j<=2 || dp[j+1][i-1]))
                {
                    dp[j][i]=1;
                    if(i-j+1>len)
                    {
                        len=i-j+1;
                        left=j;
                        right=i;
                    }
                }
            }
        }
        return s.substr(left,right-left+1);
    }
};