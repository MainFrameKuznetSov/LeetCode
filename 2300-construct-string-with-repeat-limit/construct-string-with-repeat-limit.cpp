class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        sort(s.rbegin(),s.rend());
        string ans;
        int cnt=1,ptr=0;
        for(int i=0;i<s.size();++i)
        {
            if(ans.size()!=0 && ans.back()==s[i])
            {
                if(cnt<lim)
                {
                    ans+=s[i];
                    ++cnt;
                }
                else
                {
                    ptr=max(ptr,i+1);
                    while(ptr<s.size() && s[ptr]==s[i])
                        ++ptr;
                    if(ptr<s.size())
                    {
                        ans+=s[ptr];
                        swap(s[i],s[ptr]);
                        cnt=1;
                    }
                    else
                        break;
                }
            }
            else
            {
                ans+=s[i];
                cnt=1;
            }
        }
        return ans;
    }
};