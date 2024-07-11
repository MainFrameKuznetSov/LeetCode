class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<pair<char,int>>stk;
        vector<pair<int,int>>res;
        string ans="";
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
                stk.push(make_pair(s[i],i));
            else if(s[i]==')')
            {
                res.push_back(make_pair(i,stk.top().second));
                stk.pop();
            }
        }
        for(int i=0;i<res.size();++i)
            reverse(s.begin()+res[i].second,s.begin()+res[i].first+1);
        for(int i=0;i<n;++i)
        {
            if(s[i]!='(' && s[i]!=')')
                ans+=s[i];
        }
        return ans;
    }
};