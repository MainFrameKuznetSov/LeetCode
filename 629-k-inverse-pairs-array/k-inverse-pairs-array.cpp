class Solution {
public:
    int kInversePairs(int n, int k) {
        int MOD=1e9+7;
        vector<int>prev(k+1,0);
        prev[0]=1;
        for(int i=1;i<=n;++i)
        {
            vector<int>curr(k+1,0);
            curr[0]=1;
            for(int j=0;j<=k;++j)
            {
                curr[j]=prev[j]%MOD;
                if(j)
                    curr[j]=(prev[j]+curr[j-1])%MOD;
                if(j>=i)
                    curr[j]=(curr[j]+MOD-prev[j-i])%MOD;
            }
            prev=curr;
        }
        return prev[k];
    }
};