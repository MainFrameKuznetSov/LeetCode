class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        for(char ch:s)
        {
            if(stk.empty())
                stk.push(ch);
            else if(ch==')' && stk.top()=='(')
            {
                stk.pop();
                continue;
            }
            else
                stk.push(ch);
        }
        return stk.size();
    }
};