class Solution {
public:
    unordered_map<string,bool>mp;
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return 1;
        if(s1.size()!=s2.size())
            return 0;
        int n=s1.size();
        if(n==0)
            return 1;
        bool flag=0;
        string val=s1+"_"+s2;
        if(mp.find(val)!=mp.end())
            return mp[val];
        for(int i=1;i<n;++i)
        {
            bool ch1=isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
            bool ch2=isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            if(ch1 || ch2)
            {
                flag=1;
                break;
            }
        }
        mp[val]=flag;
        return flag;
    }
};