class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size(),c1=0,c0=0,pwr=1,sum=0;
        for(int i=n-1;i>=0 && sum<=k-pwr;--i)
        {
            if(s[i]=='1')
            {
                ++c1;
                sum+=pwr;
            }
            pwr<<=1;
        }
        for(char c:s)
        {
            if(c=='0')
                ++c0;
        }
        return c0+c1;
    }
};