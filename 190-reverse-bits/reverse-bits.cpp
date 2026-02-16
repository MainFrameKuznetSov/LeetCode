class Solution {
public:

    int getNum(vector<int>&bits)
    {
        long long ans=0;
        for(int i=0;i<=31;++i)
            ans+=(bits[i]<<i);
        return (int)ans;
    }

    int reverseBits(int n) {
        vector<int>bits(32,0);
        int ind=31;
        while(n)
        {
            bits[ind--]=n%2;
            n>>=1;
        }
        return getNum(bits);
    }
};