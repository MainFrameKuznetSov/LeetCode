class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>l(26,-1),r(26,-1);
        for(int i=0;i<s.size();++i)
        {
            int ascii=s[i]-'a';
            if(l[ascii]==-1)
                l[ascii]=i;
            r[ascii]=i;
        }
        int ans=0;  
        for(int i=0;i<26;++i)
        {
            if(l[i]!=-1)
            {
                unordered_set<char>sub;
                for(int j=l[i]+1;j<r[i];++j)
                    sub.insert(s[j]);
                ans+=sub.size();
            }
        }
        return ans;
    }
};