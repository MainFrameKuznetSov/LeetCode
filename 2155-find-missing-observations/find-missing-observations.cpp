class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(),nsum=0,len=n+m;
        for(int it:rolls)
            nsum+=it;
        int msum=mean*len-nsum;
        if(n*6<msum || msum<n)
            return {};
        int rem=msum%n,quo=msum/n;
        vector<int>ans(n,quo);
        for(int i=1;i<=rem;++i)
            ++ans[i];
        return ans;
    }
};