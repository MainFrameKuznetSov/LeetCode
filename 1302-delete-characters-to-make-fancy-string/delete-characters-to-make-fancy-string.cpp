class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3)
            return s;
        string ans="";
        ans+=s[0];
        ans+=s[1];
        for(int i=2;i<s.size();++i)
        {
            char c=s[i];
            if(s[i-1]==c && s[i-2]==c)
                continue;
            else
                ans+=c;
        }
        return ans;
    }
};