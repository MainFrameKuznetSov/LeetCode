class Solution {
public:
    long long solve(long long a,long long b,int &n)
    {
        int ans=0;
        while(a<=n)
        {
            ans+=min((long long)n+1,b)-a;
            a*=10;
            b*=10;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        int ans=1;
        for(int i=1;i<k;)
        {
            long long temp=solve(ans,ans+1,n);
            if(i+temp<=k)
            {
                i+=temp;
                ++ans;
            }
            else
            {
                ++i;
                ans*=10;
            }
        }
        return ans;
    }
};