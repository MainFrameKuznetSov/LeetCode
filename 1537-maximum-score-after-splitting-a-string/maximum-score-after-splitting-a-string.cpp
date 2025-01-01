class Solution {
public:
    int maxScore(string s) {
        int one=0,zero=0,ans=INT_MIN,n=s.size();
        for(int i=0;i<n-1;++i)
        {
            if(s[i]=='0')
                ++zero;
            else
                ++one;
            ans=max(ans,zero-one);
        }
        if(s[n-1]=='1')
            return ans+one+1;
        return ans+one;
    }
};