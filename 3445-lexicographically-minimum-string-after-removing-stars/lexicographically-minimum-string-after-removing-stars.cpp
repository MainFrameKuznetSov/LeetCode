class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>>frq(26);
        int ch='a',n=s.size();
        string ans="";
        for(int i=0;i<n;++i)
        {
            if(s[i]=='*')
            {
                for(int j=0;j<26;++j)
                {
                    if(!frq[j].empty())
                    {
                        frq[j].pop_back();
                        break;
                    }
                }
            }
            else
                frq[s[i]-ch].push_back(i);
        }
        vector<bool>vis(n,0);
        for(auto it:frq)
        {
            for(int ind:it)
                vis[ind]=1;
        }
        for(int i=0;i<n;++i)
        {
            if(vis[i])
                ans+=s[i];
        }
        return ans;
    }
};