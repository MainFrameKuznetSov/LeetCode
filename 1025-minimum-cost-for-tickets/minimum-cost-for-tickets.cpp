class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last=days[days.size()-1];
        vector<int>dp(last+1,0);
        int cnt=0;
        for(int i=1;i<=last;++i)
        {
            if(i<days[cnt])
                dp[i]=dp[i-1];
            else
            {
                ++cnt;
                dp[i]=dp[i-1]+costs[0];
                if(i>7)
                    dp[i]=min(dp[i],dp[i-7]+costs[1]);
                else
                    dp[i]=min(dp[i],dp[0]+costs[1]);
                if(i>30)
                    dp[i]=min(dp[i],dp[i-30]+costs[2]);
                else
                    dp[i]=min(dp[i],dp[0]+costs[2]);
            }
        }
        return dp[last];
    }
};