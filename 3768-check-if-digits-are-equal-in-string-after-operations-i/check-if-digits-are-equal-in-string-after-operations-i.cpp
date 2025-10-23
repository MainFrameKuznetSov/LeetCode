class Solution {
public:
    bool hasSameDigits(string s) {
        int i=0;
        string ans="";
        while(s.size()>2 && i+1<s.size())
        {
            ans+=(s[i]+s[i+1])%10;
            ++i;
            if(i+1==s.size())
            {
                s=ans;
                i=0;
                ans="";
            }
        }
        return (s.size()==2 && s[0]==s[1]);
    }
};