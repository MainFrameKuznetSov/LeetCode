class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string s:strs) 
        {
            int zer=count(s.begin(),s.end(),'0'),one=s.size()-zer;
            for(int i=m;i>=zer;--i) 
            {
                for(int j=n;j>=one;--j)
                    dp[i][j]=max(dp[i][j],dp[i-zer][j-one]+1);
            }
        }
        return dp[m][n];
    }
};