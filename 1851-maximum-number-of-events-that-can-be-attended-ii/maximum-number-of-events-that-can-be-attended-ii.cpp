class Solution {
public:

    int f(vector<vector<int>>&dp,vector<vector<int>>&events,int n,int ind,int k)
    {
        if(ind>=n || k==0)
            return 0;

        if(dp[ind][k]!=-1)
            return dp[ind][k];

        int i;
        for(i=ind+1;i<n;++i)
        {
            if(events[i][0]>events[ind][1])
                break;
        }

        return dp[ind][k]=max(f(dp,events,n,ind+1,k),events[ind][2]+f(dp,events,n,i,k-1));

    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(dp,events,n,0,k);
    }
};