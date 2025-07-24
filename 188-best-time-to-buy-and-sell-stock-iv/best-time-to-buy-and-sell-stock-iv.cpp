class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        //vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        vector<vector<int>>dp(n,vector<int>(k*2+1,0));
        vector<int>prev(k*2+1,0);
        for(int i=0;i<k*2;++i)
        {
            if(i%2!=0)
                prev[i]=prices[n-1];
        }
        for(int i=n-2;i>=0;--i)
        {
            vector<int>curr(k*2+1,0);
            for(int j=k*2-1;j>=0;--j)
            {
                int Buy=0,notBuy=0;
                if(j%2==0)//Buy
                {
                    int notTake=prev[j];
                    int Take=-prices[i]+prev[j+1];
                    Buy=max(notTake,Take);
                }
                else
                {
                    int notTake=prev[j];
                    int Take=prices[i]+prev[j+1];
                    notBuy=max(notTake,Take);
                }
                curr[j]=max(Buy,notBuy);
            }
            prev=curr;
        }
        return prev[0];
    }
};