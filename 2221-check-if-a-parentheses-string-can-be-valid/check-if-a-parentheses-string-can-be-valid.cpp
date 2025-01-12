class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n&1)
            return 0;
        stack<int>open,lock;
        for(int i=0;i<n;++i)
        {
            if(locked[i]=='0')
                lock.push(i);
            else if(s[i]=='(')
                open.push(i);
            else if(s[i]==')')
            {
                if(!open.empty())
                    open.pop();
                else if(!lock.empty())
                    lock.pop();
                else
                    return 0;
            }
        }

        while(!open.empty() && !lock.empty() && open.top()<lock.top())
        {
            open.pop();
            lock.pop();
        }

        if(open.empty() && !lock.empty())
            return lock.size()%2==0;

        return open.empty();
    }
};