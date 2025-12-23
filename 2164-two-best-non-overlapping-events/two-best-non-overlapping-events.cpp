class Solution {
public:
    vector<vector<int>>events,dp;
    vector<int>temp;

    int dfs(int i,int k) 
    {
        if(i==events.size() || k==2) 
            return 0;
        if(dp[i][k]!=-1) 
            return dp[i][k];
        
        int ans=dfs(i+1,k);

        int nxt=lower_bound(temp.begin(),temp.end(),events[i][1]+1)-temp.begin();
        ans=max(ans,events[i][2]+dfs(nxt,k+1));

        return dp[i][k]=ans;
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        this->events=events;
        int n=events.size();
        temp.resize(n);
        for(int i=0;i<n;++i) 
            temp[i]=events[i][0];
        dp.assign(n,vector<int>(3,-1));
        return dfs(0,0);
    }
};