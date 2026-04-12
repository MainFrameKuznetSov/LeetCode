class Solution {
public:
    int helper(int a,int b) 
    {
        return abs(a/6-b/6)+abs(a%6-b%6);
    }

    int minimumDistance(string s) {
        int n=s.size();
        vector<int>pre(26);
        for(int i=1;i<n;++i) 
        {
            int p=s[i-1]-'A',t=s[i]-'A';
            vector<int>cur(26);
            for(int j=0;j<26;++j)
                cur[j]=pre[j]+helper(p,t);
            for(int j=0;j<26;++j)
                cur[p]=min(cur[p],pre[j]+helper(j,t));
            swap(pre,cur);
        }
        int ans=INT_MAX;
        for(int i:pre)
            ans=min(ans,i);
        return ans;
    }
};