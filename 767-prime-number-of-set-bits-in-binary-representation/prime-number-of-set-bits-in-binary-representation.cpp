class Solution {
public:

    bool isPrime(int x)
    {
        if(x==0 || x==1)
            return false;
        for(int i=2;i*i<=x;++i)
        {
            if(x%i==0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;++i)
        {
            if(isPrime(__builtin_popcount(i)))
                ++ans;
        }
        return ans;
    }
};