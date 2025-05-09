class Solution {

int MOD=1e9+7;
vector<int>f,inv,finv;

private:
    void precomp(int n)
    {
        f=vector<int>(n+1,1);
        inv=vector<int>(n+1,1);
        finv=vector<int>(n+1,1);
        for(int i=1;i<=n;++i)
            f[i]=(1LL*f[i-1]*i)%MOD;
        for(int i=2;i<=n;++i)
            inv[i]=MOD-1LL*(MOD/i)*inv[MOD%i]%MOD;
        for(int i=1;i<=n;++i)
            finv[i]=(1LL*finv[i-1]*inv[i])%MOD; 
    }

public:
    int countBalancedPermutations(string num) {
        int n=num.size(),sum=0;
        for(char c:num)
            sum+=c-'0';
        if(sum&1)
            return 0;
        precomp(n);
        int hsum=sum>>1,hlen=n>>1;
        vector<vector<int>>dp(hsum+1,vector<int>(hlen+1));
        dp[0][0]=1;
        vector<int>dig(10,0);
        for(int i=0;i<n;++i)
        {
            int d=num[i]-'0';
            ++dig[d];
            for(int j=hsum;j>=d;--j)
            {
                for(int k=hlen;k>=1;--k)
                    dp[j][k]=(dp[j][k]+dp[j-d][k-1])%MOD;
            }
        }
        int ans=dp[hsum][hlen];
        ans=1LL*ans*f[hlen]%MOD;
        ans=1LL*ans*f[n-hlen]%MOD;
        for(int i:dig)
            ans=(1LL*ans*finv[i])%MOD;
        return ans;
    }
};