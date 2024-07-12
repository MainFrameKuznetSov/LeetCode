class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a=0,b=0,ans=0,n=s.size(),pt=min(x,y);
        for(int i=0;i<n;++i)
        {
            if(s[i]>'b')
            {
                ans+=min(a,b)*pt;
                a=0;
                b=0;
            }
            else if(s[i]=='a')
            {
                if(x<y && b>0)
                {
                    --b;
                    ans+=y;
                }
                else 
                    ++a;
            }
            else
            {
                if(x>y && a>0)
                {
                    --a;
                    ans+=x;
                }
                else
                    ++b;
            }
        }
        ans+=min(a,b)*pt;
        return ans;
    }
};