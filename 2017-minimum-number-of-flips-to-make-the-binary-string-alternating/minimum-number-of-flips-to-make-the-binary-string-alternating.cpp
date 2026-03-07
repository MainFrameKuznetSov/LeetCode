class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),e0=0,e1=0,o0=0,o1=0;
        for(int i=0;i<n;++i)
        {
            if(i&1)
            {
                if(s[i]=='1')
                    ++o1;
                else
                    ++o0;
            }
            else
            {
                if(s[i]=='1')
                    ++e1;
                else
                    ++e0;
            }
        }
        int s0=o0+e0,s1=o1+e1,ans=min(e0+o1,e1+o0);
        if(n&1)
        {
            for(int i=0;i<n-1;++i)
            {
                if(s[i]=='0')
                {
                    swap(o1,e1);
                    e0=o0+1;
                    o0=s0-e0;
                }
                else
                {
                    swap(o0,e0);
                    e1=o1+1;
                    o1=s1-e1;
                }
                ans=min(ans,min(e0+o1,e1+o0));
            }
        }
        return ans;
    }
};