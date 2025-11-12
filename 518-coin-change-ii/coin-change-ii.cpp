#define ull unsigned long long

class Solution {
public:

    int memo(int ind,vector<int>&coins,int tar)
    {
        if(tar==0)
            return 1;
        if(ind==0)
            return tar%coins[0]==0?1:0;
        int notTake=memo(ind-1,coins,tar),Take=0;
        if(tar-coins[ind]>=0)
            Take=memo(ind,coins,tar-coins[ind]);
        return notTake+Take;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // return memo(n-1,coins,amount);
        vector<ull>pre(amount+1,0);
        pre[0]=1;
        for(int i=1;i<=amount;++i)
            pre[i]=i%coins[0]==0?1:0;
        for(int i=1;i<n;++i)
        {
            vector<ull>cur(amount+1,0);
            cur[0]=1;
            for(int j=1;j<=amount;++j)
            {
                ull notTake=pre[j],Take=0;
                if(j-coins[i]>=0)
                    Take=cur[j-coins[i]];
                cur[j]=notTake+Take;
            }
            pre=cur;
        }
        return pre[amount];
    }
};