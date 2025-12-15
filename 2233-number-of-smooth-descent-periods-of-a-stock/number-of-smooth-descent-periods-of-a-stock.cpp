#define ll long long

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        ll cnt=1,ans=0;
        for(int i=1;i<n;++i)
        {
            ans+=cnt;
            if(prices[i-1]-prices[i]==1)
                ++cnt;
            else
                cnt=1;
        }
        return (ans+cnt);
    }
};