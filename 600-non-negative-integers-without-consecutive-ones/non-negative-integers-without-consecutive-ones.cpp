class Solution {
public:
    int findIntegers(int n) {
        int fibo[32];
        fibo[0]=1;
        fibo[1]=2;
        for(int i=2;i<32;++i)
            fibo[i]=fibo[i-1]+fibo[i-2];
        int ans=0,k=30,msk=0;
        while(k>=0)
        {
            if(n & (1<<k))
            {
                ans+=fibo[k];
                if(msk)
                    return ans;
                else
                    msk=1;
            }
            else
                msk=0;
            --k;
        }
        return ++ans;
    }
};