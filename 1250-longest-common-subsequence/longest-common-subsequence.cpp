class Solution {
public:

    int f(int ind1,int ind2,string &text1,string &text2
    ,vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        if(text1[ind1]==text2[ind2])
            return dp[ind1][ind2]=1+f(ind1-1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2]=max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int>pre(m+1,0);
        for(int i=1;i<=n;++i)
        {
            vector<int>cur(m+1,0);
            for(int j=1;j<=m;++j)
            {
                if(text1[i-1]==text2[j-1])
                    cur[j]=1+pre[j-1];
                else
                cur[j]=max(pre[j],cur[j-1]);
            }
            swap(pre,cur);
        }
        return pre[m];
    }
};