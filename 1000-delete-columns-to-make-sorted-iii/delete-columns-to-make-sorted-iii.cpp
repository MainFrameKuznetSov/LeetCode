class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size(),n=strs[0].size(),ans=1;  
        vector<int>dp(n,1);
        for(int i=0;i<n;++i) 
        {
            for(int j=0;j<i;++j) 
            {
                bool flag=1;
                for(int k=0;k<m;++k) 
                {
                    if(strs[k][j]>strs[k][i]) 
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        return (n-ans);
    }
};
