class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n,0);
        for(auto it:shifts)
        {
            if(it[2]==1)
            {
                ++diff[it[0]];
                if(it[1]<n-1)
                    --diff[it[1]+1];
            }
            else
            {
                --diff[it[0]];
                if(it[1]<n-1)
                    ++diff[it[1]+1];
            }
        }
        string ans(n,' ');
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            cnt=(cnt+diff[i])%26;
            if(cnt<0)
                cnt+=26;
            ans[i]='a'+(s[i]-'a'+cnt)%26;
        }
        return ans;
    }
};