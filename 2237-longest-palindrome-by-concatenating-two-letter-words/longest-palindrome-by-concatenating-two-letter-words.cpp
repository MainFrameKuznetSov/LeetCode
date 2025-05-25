class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>>cnt(26,vector<int>(26,0));
        int ans=0;
        for(string s:words)
        {
            int F=s[0]-'a',S=s[1]-'a';
            if(cnt[S][F])
            {
                ans+=4;
                --cnt[S][F];
            }
            else
                ++cnt[F][S];
        }
        for(int i=0;i<26;++i)
        {
            if(cnt[i][i])
            {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};