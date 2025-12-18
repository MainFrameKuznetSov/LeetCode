#define ll long long

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<ll>preP(n+1),preS(n+1);
        for(int i=0;i<n;++i) 
        {
            preP[i+1]=preP[i]+(prices[i]*strategy[i]);
            preS[i+1]=preS[i]+prices[i];
        }
        ll ans=preP[n];
        for(int i=k-1;i<n;++i) 
        {
            ll left=preP[i-k+1],right=preP[n]-preP[i+1];
            ll diff=preS[i+1]-preS[i-k/2+1];
            ans=max(ans,left+right+diff);
        }
        return ans;
    }
};