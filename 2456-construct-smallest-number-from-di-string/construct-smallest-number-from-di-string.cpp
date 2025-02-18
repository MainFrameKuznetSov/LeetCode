class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char>stk;
        string ans="";
        int n=pattern.size()+1;
        for(int i=1;i<=n;++i)
        {
            stk.push('0'+i);
            if(pattern[i-1]=='I' || i==n)
            {
                while(!stk.empty())
                {
                    ans+=stk.top();
                    stk.pop();
                }
            }
        }
        return ans;
    }
};