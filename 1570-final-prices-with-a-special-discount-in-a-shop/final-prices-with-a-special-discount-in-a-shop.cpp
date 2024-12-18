class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && prices[j]>prices[i])
                ++j;
            if(j<n)
                prices[i]-=prices[j];
        }
        return prices;
    }
};