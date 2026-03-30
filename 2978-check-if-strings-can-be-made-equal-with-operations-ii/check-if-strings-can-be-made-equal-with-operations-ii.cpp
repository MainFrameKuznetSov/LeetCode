class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>e1(26,0),o1(26,0),e2(26,0),o2(26,0);
        for(int i=0;i<s1.size();++i)
        {
            if(i&1)
            {
                ++o1[s1[i]-'a'];
                ++o2[s2[i]-'a'];
            }
            else
            {
                ++e1[s1[i]-'a'];
                ++e2[s2[i]-'a'];
            }
        }

        for(int i=0;i<26;++i)
        {
            if(e1[i]!=e2[i] || o1[i]!=o2[i])
                return false;
        }
        return true;
    }
};