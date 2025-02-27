class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans=0,n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            mp[arr[i]]=i;
            for(int j=0;j<i;++j)
            {
                int diff=arr[i]-arr[j],pre=-1;
                if(mp.find(diff)!=mp.end())
                    pre=mp[diff];
                if(diff<arr[j] && pre>=0)
                    dp[j][i]=dp[pre][j]+1;
                else
                    dp[j][i]=2;
                ans=max(ans,dp[j][i]);
            }
        }
        if(ans>2)
            return ans;
        return 0;
    }
};