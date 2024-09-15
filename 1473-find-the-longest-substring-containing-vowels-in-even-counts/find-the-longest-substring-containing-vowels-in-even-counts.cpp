class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size(),msk=0,ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='a')
                msk^=(1<<0);
            else if(s[i]=='e')
                msk^=(1<<1);
            else if(s[i]=='i')
                msk^=(1<<2);
            else if(s[i]=='o')
                msk^=(1<<3);
            else if(s[i]=='u')
                msk^=(1<<4);
            if(mp.find(msk)!=mp.end())
                ans=max(ans,i-mp[msk]);
            else
                mp[msk]=i;
        }
        return ans;
    }
};