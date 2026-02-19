class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size(),ind=1,pre=1,ans=0,curr=1;
        if(n==1)
            return ans;
        while(s[ind-1]==s[ind++])
            ++pre;
        while(ind<n)
        {
            while(s[ind]==s[ind-1])
            {
                ++curr;
                ++ind;
            }
            ans+=min(pre,curr);
            pre=curr;
            curr=1;
            ++ind;
        }
        return ans+(s[n-1]!=s[n-2]?min(pre,curr):0);
    }
};