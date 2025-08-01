class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0,n=s.size();
        for(int i=1;i<n;++i)
        {
            if(mp[s[i]]>mp[s[i-1]])
                ans-=mp[s[i-1]];
            else
                ans+=mp[s[i-1]];
        }
        ans+=mp[s[n-1]];
        return ans;
    }
};