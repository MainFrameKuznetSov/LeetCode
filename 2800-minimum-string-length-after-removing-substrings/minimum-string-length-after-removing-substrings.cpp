class Solution {
public:
    int minLength(string s) {
        stack<char>stk;
        for(char ch:s)
        {
            if(stk.empty())
            {
                stk.push(ch);
                continue;
            }
            if(ch=='B' && stk.top()=='A')
                stk.pop();
            else if(ch=='D' && stk.top()=='C')
                stk.pop();
            else
                stk.push(ch);
        }
        return stk.size();
    }
};