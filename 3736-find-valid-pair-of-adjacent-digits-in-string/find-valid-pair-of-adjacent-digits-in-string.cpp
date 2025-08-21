class Solution {
public:
    string findValidPair(string s) {
        string ans="";
        vector<int>freq(10,0);
        for(char c:s)
            ++freq[c-'0'];
        for(int i=1;i<s.size();++i)
        {
            if(s[i]!=s[i-1] && freq[s[i]-'0']==(int)(s[i]-'0') && freq[s[i-1]-'0']==(int)(s[i-1]-'0'))
            {
                ans+=s[i-1];
                ans+=s[i];
                return ans;
            }
        }
        return "";
    }
};