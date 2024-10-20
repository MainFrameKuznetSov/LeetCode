class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>stk;
        for(char c:exp)
        {
            if(c==',' || c=='(')
                continue;
            else if(c==')')
            {
                bool t=0,f=0;
                while(stk.top()!='!' && stk.top()!='&' && stk.top()!='|')
                {
                    char ch=stk.top();
                    stk.pop();
                    if(ch=='t')
                        t=1;
                    if(ch=='f')
                        f=1;
                }
                char ch=stk.top();
                stk.pop();
                if(ch=='!')
                    stk.push(t?'f':'t');
                else if(ch=='&')
                    stk.push(f?'f':'t');
                else
                    stk.push(t?'t':'f');
            }
            else
                stk.push(c);
        }
        return stk.top()=='t';
    }
};