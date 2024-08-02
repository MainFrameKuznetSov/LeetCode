class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        int dp[n+1];
        dp[n]=dp[n-1]=0;
        for(int i=n-2;i>=0;--i) 
        {
            if(abs(word[i+1]-word[i])<=1) 
                dp[i]=min(dp[i+1],dp[i+2])+1;
            else 
                dp[i]=dp[i+1];
        }
        return dp[0];
    }
};