class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>cnt(3,0);
        for(char c:s)
            ++cnt[c-'a'];
        
        int mn=INT_MAX;
        for(int i=0;i<cnt.size();++i)
            mn=min(mn,cnt[i]);
        if(mn<k)
            return -1;
        
        int res=INT_MAX,l=0;
        for(int r=0;r<s.size();++r)
        {
            --cnt[s[r]-'a'];
            while(*min_element(cnt.begin(),cnt.end())<k)
            {
                ++cnt[s[l]-'a'];
                ++l;
            }
            res=min(res,(int)s.size()-(r-l+1));
        }
        return res;
    }
};