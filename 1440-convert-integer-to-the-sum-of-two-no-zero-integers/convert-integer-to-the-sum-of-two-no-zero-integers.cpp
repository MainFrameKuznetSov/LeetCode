class Solution {
public:

    bool isNonZero(int n)
    {
        while(n)
        {
            int d=n%10;
            if(d==0)
                return false;
            n/=10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n-1;++i)
        {
            if(isNonZero(i) && isNonZero(n-i))
                return {i,n-i};
        }
        return {};
    }
};