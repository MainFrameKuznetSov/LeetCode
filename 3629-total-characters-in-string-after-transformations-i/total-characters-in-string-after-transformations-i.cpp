class Solution {
public:
    long long exp(long long a,long long b,long long c)
    {
        long long res=1;
        a=a%c;   
        if(a==0) 
            return 0;
        while(b>0) 
        { 
            if(b&1) 
                res=(res*a)%c; 
            b=b>>1;
            a=(a*a)%c; 
        } 
        return res;
    }
    int lengthAfterTransformations(string s, int t) {
        //t=t%26;
        long long mod=1e9+7,ans=0;
        /*for(int i=0;i<s.size();++i)
        {
            int curr=(int)(s[i]-'a');
            curr=curr%26;
            int trunc=(curr+t)/26;
            ans=(ans+exp(2,trunc,mod))%mod;
        }
        return (int)ans;*/
        vector<int>prev(26,0);
        for(char c:s)
            ++prev[c-'a'];

        for(int i=0;i<t;++i)
        {
            vector<int>curr(26,0);
            for(int j=0;j<26;++j)
            {
                if(j==25)
                {
                    curr[0]=(curr[0]+prev[j])%mod;
                    curr[1]=(curr[1]+prev[j])%mod;
                }
                else
                    curr[j+1]=(curr[j+1]+prev[j])%mod;
            }    
            prev=curr;
        }
        for(int i=0;i<26;++i)
            ans=(ans+prev[i])%mod;
        return (int)ans;
    }
};