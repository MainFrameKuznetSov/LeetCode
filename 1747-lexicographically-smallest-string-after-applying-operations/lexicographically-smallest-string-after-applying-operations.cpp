class Solution {
public:

    void helper(string &s,int b)
    {
        int n=s.size();
        b%=n;
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        string temp=s;
        unordered_set<string>vis;
        queue<string>q;
        vis.insert(s);
        q.push(s);
        while(!q.empty())
        {
            string node=q.front();
            q.pop();
            if(node<temp)
                temp=node;

            string newS=node;
            for(int i=1;i<newS.size();i+=2)
                newS[i]=((newS[i]-'0'+a)%10)+'0';

            if(!vis.count(newS))
            {
                vis.insert(newS);
                q.push(newS);
            }

            helper(node,b);
            if(!vis.count(node))
            {
                vis.insert(node);
                q.push(node);
            }
        }
        return temp;
    }
};