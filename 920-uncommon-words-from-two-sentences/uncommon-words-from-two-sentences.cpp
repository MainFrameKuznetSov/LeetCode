class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1+=" ";
        s2+=" ";
        unordered_map<string,int>mp;
        string temp="";
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]==' ')
            {
                ++mp[temp];
                temp="";
            }
            else
                temp+=s1[i];
        }
        temp="";
        for(int i=0;i<s2.size();++i)
        {
            if(s2[i]==' ')
            {
                ++mp[temp];
                temp="";
            }
            else
                temp+=s2[i];
        }
        vector<string>ans;
        for(auto iter:mp)
        {
            if(iter.second==1)
                ans.push_back(iter.first);
        }
        return ans;
    }
};