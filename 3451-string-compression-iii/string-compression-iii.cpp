class Solution {
public:
    string compressedString(string s) {
        int n=s.size();
        if(n==1)
            return "1"+s;
        string ans="";
        int c=1;
        for(int i=0;i<n-1;++i)
        {
            if(s[i]==s[i+1])
                ++c;
            else
            {
                if(c<=9)
                    ans+=to_string(c)+s[i];
                else
                {
                    int times=c/9,rem=c%9;
                    for(int j=1;j<=times;++j)
                        ans+=to_string(9)+s[i];
                    if(rem>0)
                        ans+=to_string(rem)+s[i];
                }
                c=1;
            }
        }
        if(c!=0)
        {
            if(c<=9)
                ans+=to_string(c)+s[n-1];
            else
            {
                int times=c/9,rem=c%9;
                for(int j=1;j<=times;++j)
                    ans+=to_string(9)+s[n-1];
                if(rem>0)
                    ans+=to_string(rem)+s[n-1];
            }
        }
        return ans;
        //return "";
    }
};