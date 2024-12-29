class Solution {
public:

    void dfs(string pre,string &ans,unordered_set<string>&vis, int k)
    {
        for(int i=0;i<k;++i)
        {
            string temp=pre+to_string(i);
            if(vis.find(temp)!=vis.end())   
                continue;
            vis.insert(temp);
            dfs(temp.substr(1,pre.size()),ans,vis,k);
            ans+=to_string(i);
        }
    }

    string crackSafe(int n, int k) {
        if(n==1 && k==1)
            return "0";
        unordered_set<string>vis;
        string ans,pre(n-1,'0');
        dfs(pre,ans,vis,k);
        ans+=pre;
        return ans;
    }
};