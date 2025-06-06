class Solution {
public:

    char helper(vector<int>&frq)
    {
        for(int i=0;i<26;++i)
        {
            if(frq[i])
                return 'a'+i;
        }
        return 'a';
    }

    string robotWithString(string s) {
        vector<int>frq(26,0);
        for(auto i:s)
            ++frq[i-'a'];
        string ans="";
        stack<char>stk;
        for(auto i:s)
        {
            stk.push(i);
            --frq[i-'a'];
            while(!stk.empty() && stk.top()<=helper(frq))
            {
                char node=stk.top();
                stk.pop();
                ans+=node;
            }
        }
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }   
        return ans;
    }
};