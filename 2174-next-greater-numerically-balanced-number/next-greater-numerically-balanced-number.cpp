class Solution {
public:

    bool helper(int n)
    {
        vector<int>frq(10,0);
        while(n)
        {
            ++frq[n%10];
            n/=10;
        }
        for(int i=0;i<10;++i)
        {
            if(frq[i] && frq[i]!=i)
                return 0;
        }
        return 1;
    }

    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;++i)
        {
            if(helper(i))
                return i;
        }
        return -1;
    }
};