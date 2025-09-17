class Solution {
public:

    int f(string &x,string &y,int ind1,int ind2,vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        if(x[ind1]==y[ind2])
            return dp[ind1][ind2]=1+f(x,y,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(f(x,y,ind1-1,ind2,dp),f(x,y,ind1,ind2-1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //return f(text1,text2,n-1,m-1,dp);
        //dp[0][0]=(text1[0]==text2[0])?1:0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};