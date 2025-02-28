class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ind=n,jnd=m;
        string ans="";
        while(ind && jnd)
        {
            if(a[ind-1]==b[jnd-1])
            {
                ans+=a[ind-1];
                --ind;
                --jnd;
            }
            else if(dp[ind-1][jnd]>dp[ind][jnd-1])
            {
                ans+=a[ind-1];
                --ind;
            }
            else
            {
                ans+=b[jnd-1];
                --jnd;
            }
        }
        while(ind)
            ans+=a[--ind];
        while(jnd)
            ans+=b[--jnd];
        reverse(ans.begin(),ans.end());
        return ans;
    }
};