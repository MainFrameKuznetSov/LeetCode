class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int>cnt;
        vector<int>pwr;
        for(int iter:power)
        {
            if(cnt.find(iter)!=cnt.end())
                ++cnt[iter];
            else
            {
                cnt[iter]=1;
                pwr.push_back(iter);
            }
        }
        sort(pwr.begin(),pwr.end());
        int n=pwr.size();
        vector<long long>dp(n,0);
        for(int i=0;i<n;++i)
        {
            long long prev=0;
            int ptr=i-1;
            while(ptr>=0 && pwr[ptr]>=pwr[i]-2)
                --ptr;
            if(ptr>=0)
                prev=dp[ptr];
            if(i==0)
                dp[i]=pwr[i]*1LL*cnt[pwr[i]]*1LL;
            else
                dp[i]=max((prev+pwr[i]*cnt[pwr[i]])*1LL,dp[i-1]);
        }
        return dp[n-1];
    }
};