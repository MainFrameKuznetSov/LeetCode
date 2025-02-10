class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        stack<char>stk;
        for(int i=0;i<n;++i)
        {
            int chk=s[i]-'0';
            if(chk>=0 && chk<=9)
            {
                if(!stk.empty())
                    stk.pop();
            }
            else
                stk.push(s[i]);
        }
        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};