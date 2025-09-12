class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size();
        map<int,int>mp;
        int v=0;
        bool odd=0,even=0;
        mp[0]=1;
        for(char ch:s)
        {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                ++v;
            if(v&1)
                odd=1;
            if(mp.find(v%2)!=mp.end())
                even=1;
            ++mp[v%2];
        }
        return odd;
    }
};