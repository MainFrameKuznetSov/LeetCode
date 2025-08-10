class Solution {
public:

    int helper(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=pow(10,n%10);
            n/=10;
        }
        return ans;
    }

    bool reorderedPowerOf2(int n) {
        int cmp=helper(n);
        for(int i=0;i<=29;++i)
        {
            if(cmp==helper(1<<i))
                return true;
        }
        return false;
    }
};