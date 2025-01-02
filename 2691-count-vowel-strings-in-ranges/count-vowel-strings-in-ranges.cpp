class Solution {
public:

    bool isValid(string s)
    {
        int n=s.size();
        if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u') && (s[n-1]=='a' || s[n-1]=='e' || s[n-1]=='i' || s[n-1]=='o' || s[n-1]=='u'))
            return 1;
        return 0;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pre(n+1,0);
        for(int i=0;i<n;++i)
        {
            pre[i+1]=pre[i];
            if(isValid(words[i]))
                ++pre[i+1];
        }
        /*
        for(int i=0;i<pre.size();++i)
            cout<<pre[i]<<" ";
        */
        vector<int>ans;
        for(int i=0;i<queries.size();++i)
            ans.push_back(pre[queries[i][1]+1]-pre[queries[i][0]]);
        /*
        for(int i=0;i<queries.size();++i)
        {
            int t=0;
            for(int j=queries[i][0];j<=queries[i][1];++j)
            {
                if(isValid(words[j]))
                    ++t;
            }
            ans.push_back(t);
        }
        */
        return ans;
    }
};