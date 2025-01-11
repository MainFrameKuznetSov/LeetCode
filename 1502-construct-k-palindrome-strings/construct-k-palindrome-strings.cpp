class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k)
            return 0;
        if(n==k)
            return 1;
        vector<int>frq(26,0);
        int odd=0;
        for(auto i:s)
            ++frq[i-'a'];
        for(auto i:frq)
        {
            if(i&1)
                ++odd;
        }
        return(k>=odd);
    }
};